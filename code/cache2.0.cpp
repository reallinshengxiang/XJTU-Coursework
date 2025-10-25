#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct CacheBlock {
    bool valid = false;
    bool dirty = false;
    uint32_t tag = 0;
    ll last_used = 0;
};

const vector<ll> valid_block_size{16, 32, 64, 128};
const vector<ll> valid_associativity{1, 2, 4, 8};

ll calculate_log2(ll n) {
    if(n <= 0) return 0;
    ll ans = 0;
    while(n >>= 1) ans++;
    return ans;
}

struct Cache {
    ll size;        // 字节单位
    ll associativity;
    ll block_size;
    ll num_sets;
    ll block_offset;
    ll index_bits;
    ll tag_bits;
    vector<vector<CacheBlock>> blocks;
    ll lru_counter = 0;
    
    // 统计信息
    ll accesses = 0;
    ll hits = 0;
    ll misses = 0;
    ll writebacks = 0;

    void init(ll fixed_size) {
        num_sets = fixed_size / (block_size * associativity);
        block_offset = calculate_log2(block_size);
        index_bits = calculate_log2(num_sets);
        tag_bits = 32 - block_offset - index_bits;
        blocks.resize(num_sets, vector<CacheBlock>(associativity));
    }

    void access(uint32_t address, bool is_write) {
        accesses++;
        uint32_t index = (address >> block_offset) & (num_sets-1);
        uint32_t tag = address >> (block_offset + index_bits);
        
        bool hit = false;
        auto& set = blocks[index];
        
        // 查找命中
        for(auto& block : set) {
            if(block.valid && block.tag == tag) {
                hit = true;
                block.last_used = ++lru_counter;
                if(is_write) block.dirty = true;
                break;
            }
        }

        if(hit) {
            hits++;
            return;
        }
        
        // 未命中处理
        misses++;
        CacheBlock* victim = nullptr;
        for(auto& block : set) { // 找invalid块
            if(!block.valid) {
                victim = &block;
                break;
            }
        }
        if(!victim) { // LRU替换
            victim = &set[0];
            for(auto& block : set) {
                if(block.last_used < victim->last_used) {
                    victim = &block;
                }
            }
            if(victim->dirty) writebacks++;
        }

        // 更新块
        victim->valid = true;
        victim->tag = tag;
        victim->dirty = is_write;
        victim->last_used = ++lru_counter;
    }
};

int main() {
    string trace_input_file;
    ll data_assoc, data_block, instr_assoc, instr_block;
    
    // 输入参数
    getline(cin, trace_input_file);
    cin >> data_assoc >> data_block >> instr_assoc >> instr_block;

    // 初始化数据Cache（固定32KB）
    Cache data_cache;
    data_cache.size = 32 * 1024;
    data_cache.associativity = data_assoc;
    data_cache.block_size = data_block;
    data_cache.init(data_cache.size);

    // 初始化指令Cache（固定128KB）
    Cache instr_cache;
    instr_cache.size = 128 * 1024;
    instr_cache.associativity = instr_assoc;
    instr_cache.block_size = instr_block;
    instr_cache.init(instr_cache.size);

    // 参数验证
    auto validate = [](ll val, const vector<ll>& valid, const string& msg) {
        if(find(valid.begin(), valid.end(), val) == valid.end()) {
            cerr << "错误：" << msg << endl;
            exit(1);
        }
    };
    
    validate(data_assoc, valid_associativity, "数据Cache相联度无效");
    validate(data_block, valid_block_size, "数据Cache块大小无效");
    validate(instr_assoc, valid_associativity, "指令Cache相联度无效");
    validate(instr_block, valid_block_size, "指令Cache块大小无效");

    ifstream trace_file(trace_input_file);
    if(!trace_file) {
        cerr << "无法打开trace文件：" << trace_input_file << endl;
        return 1;
    }

    string line;
    while(getline(trace_file, line)) {
        istringstream iss(line);
        uint32_t type, addr;
        if(!(iss >> type >> hex >> addr)) continue;

        if(type == 0 || type == 1) {  // 数据访问
            data_cache.access(addr, type == 1);
        } else if(type == 2) {        // 指令访问
            instr_cache.access(addr, false);
        }
    }

    // 输出结果
    auto print_stats = [](const Cache& c, const string& name) {
        cout << "===== " << name << "统计 =====" << endl;
        cout << "总访问次数:  " << c.accesses << endl
             << "命中次数:    " << c.hits << endl
             << "未命中次数:  " << c.misses << endl
             << "写回次数:    " << c.writebacks << endl
             << fixed << setprecision(2)
             << "命中率:      " 
             << (c.accesses ? 100.0*c.hits/c.accesses : 0.0) << "%\n\n";
    };

    print_stats(data_cache, "数据Cache");
    print_stats(instr_cache, "指令Cache");

    return 0;
}

/*
trace files/022.li.din
8192
2
16
*/ 
