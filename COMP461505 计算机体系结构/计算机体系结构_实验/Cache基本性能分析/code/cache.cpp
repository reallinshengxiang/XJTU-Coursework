#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct CacheBlock{
    bool valid=0,dirty=0;
    ll tag=0,last_used=0;
};
string trace_input_file;
string trace_input_files[8]={"address stream/cc1.din","address stream/eg.din","address stream/spice.din","address stream/tex.din","trace files/022.li.din","trace files/047.tomcatv.din","trace files/078.swm256.din","trace files/085.gcc.din"};
ll cache_size,cache_associativity,cache_block_size,num_sets;
ifstream trace_file;
const vector<ll> valid_cache_size{2,4,8,16,32,64,128,256,512,1024};
const vector<ll> valid_block_size{16,32,64,128,256};
const vector<ll> valid_associativity{1,2,4,8,16,32};
ll calculate_log2(ll n) 
{
    if(n<=0) return 0;
    ll ans=0;
    while(n>>=1) ans++;
    return ans;
}
void cache_simulator()
{
	ll block_offset_bits=calculate_log2(cache_block_size);
    ll index_bits=calculate_log2(num_sets);
    ll tag_bits=32-block_offset_bits-index_bits;
    vector<vector<CacheBlock>> cache(num_sets,vector<CacheBlock>(cache_associativity));
	ll load_totals=0,store_totals=0,fetch_instruction_totals=0,writebacks=0,lru_counter=0;
    ll load_hits=0,load_misses=0,store_hits=0,store_misses=0,fetch_instruction_hits=0,fetch_instruction_misses=0;
    string line;
    while(getline(trace_file,line)) 
	{
        istringstream iss(line);
        ll access_type,data;
        uint32_t address;
        if(!(iss>>access_type>>hex>>address)) continue;
        uint32_t index=(address>>block_offset_bits)&(num_sets-1);
        uint32_t tag=address>>(block_offset_bits+index_bits);
        bool hit=false;
        auto& set=cache[index];
        for(auto& block : set)
		{
            if(block.valid&&block.tag==tag) 
			{
                hit=true;
                lru_counter++;
                block.last_used=lru_counter;
                if(access_type==1) block.dirty=true;
                break;
            }
        }
        if(access_type==0) 
		{
            load_totals++;
            if(hit) load_hits++;
            else load_misses++;
        } 
		else if(access_type==1)
		{
            store_totals++;
            if(hit) store_hits++;
            else store_misses++;
        }
        else if(access_type==2)
		{
            fetch_instruction_totals++;
            if(hit) fetch_instruction_hits++;
            else fetch_instruction_misses++;
        }
        if(hit) continue;
        CacheBlock* victim=nullptr;
        for(auto& block : set) 
		{
            if(!block.valid) 
			{
                victim=&block;
                break;
            }
        }
        if(!victim)
		{
            victim=&set[0];
            for(auto& block : set) 
			{
                if (block.last_used<victim->last_used)  victim=&block;
            }
            if(victim->dirty) writebacks++;
        }
        victim->valid=true;
        victim->tag=tag;
        victim->dirty=(access_type==1);
        lru_counter++;
        victim->last_used=lru_counter;
    }
    cout<<"----------------------  Cache Simulator输入参数 --------------------\n";
    cout<<"输入文件：       "<<trace_input_file<<"\n";
	cout<<"统一的Cache大小："<<left<<setw(4)<<cache_size/1024<<"KB       ";
	cout<<"块大小："<<left<<setw(4)<<cache_block_size<<"B      ";
	cout<<"相联度："<<left<<setw(3)<<cache_associativity<<" 路\n";
	cout<<"Cache 替换算法使用 LRU，写失效策略选择 写分配\n\n"; 
    cout<<"---------------------- Cache 基本性能分析结果 -----------------------\n";
    cout<<"访问总次数："<<left<<setw(8)<<load_totals+store_totals+fetch_instruction_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(8)<<load_misses+store_misses+fetch_instruction_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(8)<<fixed<<setprecision(3)<<(load_misses+store_misses+fetch_instruction_misses)*100.0/(load_totals+store_totals+fetch_instruction_totals)<<"%\n";
	cout<<"其中：\n";
	cout<<"读指令次数："<<left<<setw(8)<<fetch_instruction_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(8)<<fetch_instruction_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(8)<<fixed<<setprecision(3)<<fetch_instruction_misses*100.0/fetch_instruction_totals<<"%\n";
	cout<<"读数据次数："<<left<<setw(8)<<load_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(8)<<load_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(8)<<fixed<<setprecision(3)<<load_misses*100.0/load_totals<<"%\n";
	cout<<"写数据次数："<<left<<setw(8)<<store_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(8)<<store_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(8)<<fixed<<setprecision(3)<<store_misses*100.0/store_totals<<"%\n\n\n";
}
int main() 
{
	cout<<"--------------------------------------------Cache 模拟器-----------------------------------------------\n";
	cout<<"1、自定义输入;\n2、运行已有文件;\n";
	ll opt;
	cin>>opt;
	cin.ignore();
	if(opt==1)
	{
		cout<<"请输入trace_input_file:"; 
		getline(cin,trace_input_file);
		cout<<"请输入cache大小cache_size:";
	    cin>>cache_size;
	    cout<<"请输入相联度cache_associativity:";
		cin>>cache_associativity;
		cout<<"请输入块大小cache_block_size:";
		cin>>cache_block_size;
	    if(find(valid_cache_size.begin(),valid_cache_size.end(),cache_size)==valid_cache_size.end())
		{
	        cout<<"错误：Cache大小cache_size不在有效范围内\n";
	        return 1;
	    }
	    if(find(valid_block_size.begin(),valid_block_size.end(),cache_block_size)==valid_block_size.end()) 
		{
	        cout<<"错误：块大小block_size不在有效范围内\n";
	        return 1;
	    }
	    if(find(valid_associativity.begin(),valid_associativity.end(),cache_associativity)==valid_associativity.end()) 
		{
	        cout<<"错误：相联度大小cache_associativity不在有效范围内\n";
	        return 1;
	    }
	    cache_size=cache_size*1024;
	    num_sets=cache_size/(cache_block_size*cache_associativity);
	    if(((num_sets&(num_sets-1))!=0)||num_sets==0) 
		{
	        cout<<"错误：参数组合无效（组数必须为2的幂）\n";
	        return 1;
	    }
	    trace_file.open(trace_input_file.c_str());
	    if(!trace_file.is_open()) 
	    {
	        cout<<"无法打开trace文件："<<trace_input_file<<"\n";
	        return 1;
	    }
	    cache_simulator();
	    trace_file.close();
	}
	else if(opt==2)
	{
		freopen("result.txt","w",stdout); 
		for(ll i=0;i<=7;i++)
		{
			trace_input_file=trace_input_files[i];
			for(ll j=1;j<=10;j++)
			{
				cache_size=(1<<j)*1024;
				for(ll k=0;k<=5;k++)
				{
					cache_associativity=(1<<k);
					for(ll q=4;q<=8;q++)
					{
						cache_block_size=(1<<q);
	    				num_sets=cache_size/(cache_block_size*cache_associativity);
	    				if(((num_sets&(num_sets-1))!=0)||num_sets==0)  continue;
	    				trace_file.open(trace_input_file.c_str());
					    if(!trace_file.is_open()) 
					    {
					        cout<<"无法打开trace文件："<<trace_input_file<<"\n";
					        return 1;
					    }
					    cache_simulator();
					    trace_file.close();	
					}
				}
			}
		}	
	}
    return 0;
}
/*
address stream/cc1.din
32
1
16
*/
