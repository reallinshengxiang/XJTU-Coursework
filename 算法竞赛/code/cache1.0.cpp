#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct CacheBlock{
    bool valid=0,dirty=0;
    ll tag=0,last_used=0;
};
string trace_input_file;
ll cache_size,cache_associativity,cache_block_size;
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
int main() 
{
    getline(cin,trace_input_file);
    cin>>cache_size>>cache_associativity>>cache_block_size;
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
    ll num_sets=cache_size/(cache_block_size*cache_associativity);
    if((num_sets&(num_sets-1))!=0) 
	{
        cout<<"错误：参数组合无效（组数必须为2的幂）\n";
        return 1;
    }
    ll block_offset_bits=calculate_log2(cache_block_size);
    ll index_bits=calculate_log2(num_sets);
    ll tag_bits=32-block_offset_bits-index_bits;
    vector<vector<CacheBlock>> cache(num_sets, vector<CacheBlock>(cache_associativity));
    ifstream trace_file(trace_input_file);
    if(!trace_file) 
	{
        cout<<"无法打开trace文件："<<trace_input_file<< "\n";
        return 1;
    }
    ll load_totals=0,store_totals=0,fetch_instruction_totals=0;
    ll load_hits=0,load_misses=0;
    ll store_hits=0,store_misses=0;
    ll fetch_instruction_hits=0,fetch_instruction_misses=0;
    ll writebacks=0;
    ll lru_counter=0;
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
        for(auto& block : set) {
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
        if (hit) continue;
        CacheBlock* victim = nullptr;
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
                if (block.last_used<victim->last_used)  victim = &block;
            }
            if(victim->dirty) writebacks++;
        }
        victim->valid=true;
        victim->tag=tag;
        victim->dirty=(access_type==1);
        lru_counter++;
        victim->last_used=lru_counter;
    }
    cout << "====== Cache 基本性能分析结果 ======\n";
    cout<<"访问总次数："<<left<<setw(9)<<load_totals+store_totals+fetch_instruction_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(9)<<load_misses+store_misses+fetch_instruction_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(9)<<setprecision(3)<<(load_misses+store_misses+fetch_instruction_misses)*100.0/(load_misses+store_misses+fetch_instruction_misses)<<"%\n";
    cout<<"其中：\n";
	cout<<"读指令次数："<<left<<setw(9)<<fetch_instruction_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(9)<<fetch_instruction_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(9)<<setprecision(3)<<fetch_instruction_misses*100.0/fetch_instruction_totals<<"%\n";
	cout<<"读数据次数："<<left<<setw(9)<<load_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(9)<<load_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(9)<<setprecision(3)<<load_misses*100.0/load_totals<<"%\n";
	cout<<"写数据次数："<<left<<setw(9)<<store_totals<<"   ";
	cout<<"不命中次数："<<left<<setw(9)<<store_misses<<"   ";
	cout<<"不命中率：  "<<left<<setw(9)<<setprecision(3)<<store_misses*100.0/store_totals<<"%\n";
	
    cout << "总写回次数:  " << writebacks << "\n";

    return 0;
}
/*
trace files/022.li.din
32
1
16
*/
