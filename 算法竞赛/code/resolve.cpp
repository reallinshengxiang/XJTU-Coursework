#include "resolve.h"

#include <iostream>

#define FOUND_ALL_DEF 0
#define MULTI_DEF 1
#define NO_DEF 2

std::string errSymName;

int callResolveSymbols(std::vector<ObjectFile> &allObjects);

void resolveSymbols(std::vector<ObjectFile> &allObjects) {
    int ret = callResolveSymbols(allObjects);
    if (ret == MULTI_DEF) {
        std::cerr << "multiple definition for symbol " << errSymName << std::endl;
        abort();
    } else if (ret == NO_DEF) {
        std::cerr << "undefined reference for symbol " << errSymName << std::endl;
        abort();
    }
}

/* bind each undefined reference (reloc entry) to the exact valid symbol table entry
 * Throw correct errors when a reference is not bound to definition,
 * or there is more than one definition.
 */
int callResolveSymbols(std::vector<ObjectFile> &allObjects)
{
    /* Your code here */
    // if found multiple definition, set the errSymName to problematic symbol name and return MULTIDEF;
    // if no definition is found, set the errSymName to problematic symbol name and return NODEF;
    std::unordered_map<std::string, Symbol*> mmap;
    std::unordered_map<std::string, bool> strongflag,vis;
    for (auto& obj:allObjects) 
    {
        for (auto& re:obj.relocTable) vis[re.name]=1;
    }
    for (auto& obj:allObjects)
    {     
        for (auto& symbol:obj.symbolTable)
        {
            if(!vis[symbol.name]) continue;
            if (symbol.bind==STB_GLOBAL&&symbol.index!=SHN_UNDEF&&symbol.index!=SHN_COMMON)
             {               
                if (mmap.count(symbol.name)>0&&mmap[symbol.name]->index!=SHN_COMMON&&strongflag[symbol.name]==1) 
                {
                    errSymName=symbol.name;
                    return MULTI_DEF;
                } 
                else 
                {
                    mmap[symbol.name]=&symbol;
                    strongflag[symbol.name]=1;
                }
            }
            else if(symbol.bind == STB_GLOBAL&&symbol.index==SHN_COMMON)
            {
                 if(!mmap.count(symbol.name))
                 {
                    mmap[symbol.name]=&symbol;
                    strongflag[symbol.name]=0;
                 }
            }
        }
    }
    for (auto& obj:allObjects) 
    {
        for (auto& re:obj.relocTable)
        {        
            std::string relocSymName = re.sym->name;
            if (mmap.count(relocSymName)==0) 
            {
                errSymName = relocSymName;
                return NO_DEF;
            }        
            re.sym=mmap[relocSymName];
        }
    }
    return FOUND_ALL_DEF;
}
