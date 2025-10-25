#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110,MAX_CLOCK=110;
// 指令结构
struct instruction {
    ll opt, fi, fj, fk; // 操作类型，目标寄存器，源寄存器1，源寄存器2/基址
    ll issue = -1, exec = -1, write = -1; // 时间戳
    bool issued = false, executed = false, written = false;
};
// 保留站结构
struct ReservationStation {
    bool Busy = false;
    string Op;
    double Vj = 0, Vk = 0; // 操作数值
    ll Qj = -1, Qk = -1; // 依赖的保留站/缓冲区索引
    ll A = 0; // 地址（用于 LOAD）
    ll time_remaining = 0; // 剩余执行时间
    ll ins_id = -1; // 指令编号
    double result = 0; // 执行结果
    string Qj_source, Qk_source; // 依赖的来源名称
};
// 寄存器状态
struct RegisterStatus {
    ll Qi = -1; // -1 表示数据就绪，否则指向保留站/缓冲区
    double value = 0; // 寄存器值
};
// 全局变量
instruction ins[N];
ll n,num_load,num_add,num_mult,cnt,time_load,time_add,time_mult,time_div,CLOCK = 1;
ll board[N][5]; // 时间戳表
string load_status[10][3], add_status[10][10], mult_status[10][10], register_results[33];
string history_load_status[MAX_CLOCK][10][3], history_add_status[MAX_CLOCK][10][10],history_mult_status[MAX_CLOCK][10][10],history_register[MAX_CLOCK][33];
string f_register_name[33], r_register_name[33];
vector<ReservationStation> add_rs, mult_rs, load_buffers;
RegisterStatus F_reg_status[32];
double F_reg_values[32];
double memory[1000] = {0};
bool cdb_busy = false;
// 操作类型转换
string opt_ll_to_opt(ll x) {
    if (x == 1) return "load";
    else if (x == 2) return "store";
    else if (x == 3) return "add.d";
    else if (x == 4) return "sub.d";
    else if (x == 5) return "mul.d";
    else return "div.d";
}
// 初始化
void init() {
    for (ll i = 0; i <= 31; i++) {
        r_register_name[i] = "R" + to_string(i);
        f_register_name[i] = "F" + to_string(i);
    }
    add_rs.resize(num_add + 1);
    mult_rs.resize(num_mult + 1);
    load_buffers.resize(num_load + 1);
    for (ll i = 1; i <= num_load; i++) {
        load_status[i][0] = "No";
        load_status[i][1] = "";
        load_status[i][2] = "";
    }
    for (ll i = 1; i <= num_add; i++) {
        add_status[i][0] = "No";
        add_status[i][1] = "";
        add_status[i][2] = "";
        add_status[i][3] = "";
        add_status[i][4] = "";
    }
    for (ll i = 1; i <= num_mult; i++) {
        mult_status[i][0] = "No";
        mult_status[i][1] = "";
        mult_status[i][2] = "";
        mult_status[i][3] = "";
        mult_status[i][4] = "";
    }
    for (ll i = 0; i < 32; i++) {
        F_reg_values[i] = 0.0;
        register_results[i] = "0";
    }
}

// 发布指令
bool issue_instruction(ll ins_id) {
    instruction &inst = ins[ins_id];
    if (inst.issued) return false;

    if (inst.opt == 1) { // LOAD
        for (ll i = 1; i <= num_load; i++) {
            if (!load_buffers[i].Busy) {
                load_buffers[i].Busy = true;
                load_buffers[i].Op = "LOAD";
                load_buffers[i].ins_id = ins_id;
                if (F_reg_status[inst.fk].Qi == -1) {
                    load_buffers[i].Vj = F_reg_values[inst.fk];
                    load_buffers[i].Qj = -1;
                } else {
                    load_buffers[i].Qj = F_reg_status[inst.fk].Qi;
                    load_buffers[i].Qj_source = (F_reg_status[inst.fk].Qi <= num_load) ? "Load" + to_string(F_reg_status[inst.fk].Qi) :
                                               (F_reg_status[inst.fk].Qi <= num_load + num_add) ? "Add" + to_string(F_reg_status[inst.fk].Qi - num_load) :
                                               "Mult" + to_string(F_reg_status[inst.fk].Qi - num_load - num_add);
                }
                load_buffers[i].A = inst.fj;
                load_buffers[i].time_remaining = time_load;
                F_reg_status[inst.fi].Qi = i;
                inst.issue = CLOCK;
                board[ins_id][1] = CLOCK;
                inst.issued = true;
                load_status[i][0] = "Yes";
                load_status[i][1] = to_string(inst.fj) + "(R" + to_string(inst.fk) + ")";
                register_results[inst.fi] = "Load" + to_string(i);
                cout << "Cycle " << CLOCK << ": Issued LOAD ins_id=" << ins_id << ", buffer=" << i
                     << ", Vj=" << load_buffers[i].Vj << ", Qj=" << load_buffers[i].Qj
                     << ", A=" << load_buffers[i].A << endl;
                return true;
            }
        }
    } else if (inst.opt == 3 || inst.opt == 4) { // ADD/SUB
        for (ll i = 1; i <= num_add; i++) {
            if (!add_rs[i].Busy) {
                add_rs[i].Busy = true;
                add_rs[i].Op = (inst.opt == 3) ? "ADD.D" : "SUB.D";
                add_rs[i].ins_id = ins_id;
                if (F_reg_status[inst.fj].Qi == -1) {
                    add_rs[i].Vj = F_reg_values[inst.fj];
                    add_rs[i].Qj = -1;
                } else {
                    add_rs[i].Qj = F_reg_status[inst.fj].Qi;
                    add_rs[i].Qj_source = (F_reg_status[inst.fj].Qi <= num_load) ? "Load" + to_string(F_reg_status[inst.fj].Qi) :
                                         (F_reg_status[inst.fj].Qi <= num_load + num_add) ? "Add" + to_string(F_reg_status[inst.fj].Qi - num_load) :
                                         "Mult" + to_string(F_reg_status[inst.fj].Qi - num_load - num_add);
                }
                if (F_reg_status[inst.fk].Qi == -1) {
                    add_rs[i].Vk = F_reg_values[inst.fk];
                    add_rs[i].Qk = -1;
                } else {
                    add_rs[i].Qk = F_reg_status[inst.fk].Qi;
                    add_rs[i].Qk_source = (F_reg_status[inst.fk].Qi <= num_load) ? "Load" + to_string(F_reg_status[inst.fk].Qi) :
                                         (F_reg_status[inst.fk].Qi <= num_load + num_add) ? "Add" + to_string(F_reg_status[inst.fk].Qi - num_load) :
                                         "Mult" + to_string(F_reg_status[inst.fk].Qi - num_load - num_add);
                }
                add_rs[i].time_remaining = time_add;
                inst.issue = CLOCK;
                board[ins_id][1] = CLOCK;
                F_reg_status[inst.fi].Qi = i + num_load;
                inst.issued = true;
                add_status[i][0] = "Yes";
                add_status[i][1] = add_rs[i].Op;
                add_status[i][2] = (add_rs[i].Qj == -1) ? to_string(add_rs[i].Vj) : add_rs[i].Qj_source;
                add_status[i][3] = (add_rs[i].Qk == -1) ? to_string(add_rs[i].Vk) : add_rs[i].Qk_source;
                register_results[inst.fi] = "Add" + to_string(i);
                cout << "Cycle " << CLOCK << ": Issued " << add_rs[i].Op << " ins_id=" << ins_id << ", add_rs=" << i
                     << ", Vj=" << add_rs[i].Vj << ", Qj=" << add_rs[i].Qj
                     << ", Vk=" << add_rs[i].Vk << ", Qk=" << add_rs[i].Qk << endl;
                return true;
            }
        }
    } else if (inst.opt == 5 || inst.opt == 6) { // MUL/DIV
        for (ll i = 1; i <= num_mult; i++) {
            if (!mult_rs[i].Busy) {
                mult_rs[i].Busy = true;
                mult_rs[i].Op = (inst.opt == 5) ? "MULT.D" : "DIV.D";
                mult_rs[i].ins_id = ins_id;
                if (F_reg_status[inst.fj].Qi == -1) {
                    mult_rs[i].Vj = F_reg_values[inst.fj];
                    mult_rs[i].Qj = -1;
                } else {
                    mult_rs[i].Qj = F_reg_status[inst.fj].Qi;
                    mult_rs[i].Qj_source = (F_reg_status[inst.fj].Qi <= num_load) ? "Load" + to_string(F_reg_status[inst.fj].Qi) :
                                          (F_reg_status[inst.fj].Qi <= num_load + num_add) ? "Add" + to_string(F_reg_status[inst.fj].Qi - num_load) :
                                          "Mult" + to_string(F_reg_status[inst.fj].Qi - num_load - num_add);
                }
                if (F_reg_status[inst.fk].Qi == -1) {
                    mult_rs[i].Vk = F_reg_values[inst.fk];
                    mult_rs[i].Qk = -1;
                } else {
                    mult_rs[i].Qk = F_reg_status[inst.fk].Qi;
                    mult_rs[i].Qk_source = (F_reg_status[inst.fk].Qi <= num_load) ? "Load" + to_string(F_reg_status[inst.fk].Qi) :
                                          (F_reg_status[inst.fk].Qi <= num_load + num_add) ? "Add" + to_string(F_reg_status[inst.fk].Qi - num_load) :
                                          "Mult" + to_string(F_reg_status[inst.fk].Qi - num_load - num_add);
                }
                mult_rs[i].time_remaining = (inst.opt == 5) ? time_mult : time_div;
                inst.issue = CLOCK;
                board[ins_id][1] = CLOCK;
                F_reg_status[inst.fi].Qi = i + num_load + num_add;
                inst.issued = true;
                mult_status[i][0] = "Yes";
                mult_status[i][1] = mult_rs[i].Op;
                mult_status[i][2] = (mult_rs[i].Qj == -1) ? to_string(mult_rs[i].Vj) : mult_rs[i].Qj_source;
                mult_status[i][3] = (mult_rs[i].Qk == -1) ? to_string(mult_rs[i].Vk) : mult_rs[i].Qk_source;
                register_results[inst.fi] = "Mult" + to_string(i);
                cout << "Cycle " << CLOCK << ": Issued " << mult_rs[i].Op << " ins_id=" << ins_id << ", mult_rs=" << i
                     << ", Vj=" << mult_rs[i].Vj << ", Qj=" << mult_rs[i].Qj
                     << ", Vk=" << mult_rs[i].Vk << ", Qk=" << mult_rs[i].Qk << endl;
                return true;
            }
        }
    }
    return false;
}

// 执行阶段
void execute() {
    for (ll i = 1; i <= num_load; i++) {
        if (load_buffers[i].Busy && load_buffers[i].Qj == -1 && load_buffers[i].time_remaining > 0) {
            load_buffers[i].time_remaining--;
            if (load_buffers[i].time_remaining == 0) {
                ll address = (ll)(load_buffers[i].Vj + load_buffers[i].A);
                load_buffers[i].result = memory[address];
                ll ins_id = load_buffers[i].ins_id;
                ins[ins_id].exec = CLOCK;
                board[ins_id][2] = CLOCK;
                ins[ins_id].executed = true;
                load_status[i][2] = "M" + to_string(i);
                cout << "Cycle " << CLOCK << ": LOAD buffer " << i << " completed, ins_id=" << ins_id
                     << ", address=" << address << ", result=" << memory[address] << endl;
            } else {
                cout << "Cycle " << CLOCK << ": LOAD buffer " << i << " executing, time_remaining=" << load_buffers[i].time_remaining << endl;
            }
        }
    }
    for (ll i = 1; i <= num_add; i++) {
        if (add_rs[i].Busy && add_rs[i].Qj == -1 && add_rs[i].Qk == -1 && add_rs[i].time_remaining > 0) {
            add_rs[i].time_remaining--;
            if (add_rs[i].time_remaining == 0) {
                if (add_rs[i].Op == "ADD.D") {
                    add_rs[i].result = add_rs[i].Vj + add_rs[i].Vk;
                } else {
                    add_rs[i].result = add_rs[i].Vj - add_rs[i].Vk;
                }
                ll ins_id = add_rs[i].ins_id;
                ins[ins_id].exec = CLOCK;
                board[ins_id][2] = CLOCK;
                ins[ins_id].executed = true;
                add_status[i][4] = "M" + to_string(i + num_load);
                cout << "Cycle " << CLOCK << ": ADD station " << i << " completed, ins_id=" << ins_id
                     << ", result=" << add_rs[i].result << endl;
            } else {
                cout << "Cycle " << CLOCK << ": ADD station " << i << " executing, time_remaining=" << add_rs[i].time_remaining << endl;
            }
        }
    }
    for (ll i = 1; i <= num_mult; i++) {
        if (mult_rs[i].Busy && mult_rs[i].Qj == -1 && mult_rs[i].Qk == -1 && mult_rs[i].time_remaining > 0) {
            mult_rs[i].time_remaining--;
            if (mult_rs[i].time_remaining == 0) {
                if (mult_rs[i].Op == "MULT.D") {
                    mult_rs[i].result = mult_rs[i].Vj * mult_rs[i].Vk;
                } else {
                    mult_rs[i].result = mult_rs[i].Vj / mult_rs[i].Vk;
                }
                ll ins_id = mult_rs[i].ins_id;
                ins[ins_id].exec = CLOCK;
                board[ins_id][2] = CLOCK;
                ins[ins_id].executed = true;
                mult_status[i][4] = "M" + to_string(i + num_load + num_add);
                cout << "Cycle " << CLOCK << ": MULT station " << i << " completed, ins_id=" << ins_id
                     << ", result=" << mult_rs[i].result << endl;
            } else {
                cout << "Cycle " << CLOCK << ": MULT station " << i << " executing, time_remaining=" << mult_rs[i].time_remaining << endl;
            }
        }
    }
}

// 写回阶段
void write_back() {
    for (ll i = 1; i <= num_load; i++) {
        if (load_buffers[i].Busy && load_buffers[i].time_remaining == 0 && !cdb_busy && ins[load_buffers[i].ins_id].executed) {
            double result = load_buffers[i].result;
            ll ins_id = load_buffers[i].ins_id;
            ll dest_reg = ins[ins_id].fi;
            F_reg_values[dest_reg] = result;
            F_reg_status[dest_reg].Qi = -1;
            for (ll j = 1; j <= num_add; j++) {
                if (add_rs[j].Qj == i) {
                    add_rs[j].Vj = result;
                    add_rs[j].Qj = -1;
                    add_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qj with " << result << endl;
                }
                if (add_rs[j].Qk == i) {
                    add_rs[j].Vk = result;
                    add_rs[j].Qk = -1;
                    add_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qk with " << result << endl;
                }
            }
            for (ll j = 1; j <= num_mult; j++) {
                if (mult_rs[j].Qj == i) {
                    mult_rs[j].Vj = result;
                    mult_rs[j].Qj = -1;
                    mult_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qj with " << result << endl;
                }
                if (mult_rs[j].Qk == i) {
                    mult_rs[j].Vk = result;
                    mult_rs[j].Qk = -1;
                    mult_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qk with " << result << endl;
                }
            }
            ins[ins_id].write = CLOCK;
            board[ins_id][3] = CLOCK;
            ins[ins_id].written = true;
            load_buffers[i].Busy = false;
            cdb_busy = true;
            register_results[dest_reg] = "";
            load_status[i][0] = "No";
            load_status[i][1] = "";
            load_status[i][2] = "";
            cout << "Cycle " << CLOCK << ": Wrote back LOAD buffer " << i << ", ins_id=" << ins_id
                 << ", result=" << result << ", dest_reg=F" << dest_reg << endl;
            return;
        }
    }
    for (ll i = 1; i <= num_add; i++) {
        if (add_rs[i].Busy && add_rs[i].time_remaining == 0 && !cdb_busy && ins[add_rs[i].ins_id].executed) {
            double result = add_rs[i].result;
            ll ins_id = add_rs[i].ins_id;
            ll dest_reg = ins[ins_id].fi;
            F_reg_values[dest_reg] = result;
            F_reg_status[dest_reg].Qi = -1;
            for (ll j = 1; j <= num_add; j++) {
                if (add_rs[j].Qj == i + num_load) {
                    add_rs[j].Vj = result;
                    add_rs[j].Qj = -1;
                    add_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qj with " << result << endl;
                }
                if (add_rs[j].Qk == i + num_load) {
                    add_rs[j].Vk = result;
                    add_rs[j].Qk = -1;
                    add_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qk with " << result << endl;
                }
            }
            for (ll j = 1; j <= num_mult; j++) {
                if (mult_rs[j].Qj == i + num_load) {
                    mult_rs[j].Vj = result;
                    mult_rs[j].Qj = -1;
                    mult_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qj with " << result << endl;
                }
                if (mult_rs[j].Qk == i + num_load) {
                    mult_rs[j].Vk = result;
                    mult_rs[j].Qk = -1;
                    mult_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qk with " << result << endl;
                }
            }
            ins[ins_id].write = CLOCK;
            board[ins_id][3] = CLOCK;
            ins[ins_id].written = true;
            add_rs[i].Busy = false;
            cdb_busy = true;
            register_results[dest_reg] = "";
            add_status[i][0] = "No";
            add_status[i][1] = "";
            add_status[i][2] = "";
            add_status[i][3] = "";
            add_status[i][4] = "";
            cout << "Cycle " << CLOCK << ": Wrote back ADD station " << i << ", ins_id=" << ins_id
                 << ", result=" << result << ", dest_reg=F" << dest_reg << endl;
            return;
        }
    }
    for (ll i = 1; i <= num_mult; i++) {
        if (mult_rs[i].Busy && mult_rs[i].time_remaining == 0 && !cdb_busy && ins[mult_rs[i].ins_id].executed) {
            double result = mult_rs[i].result;
            ll ins_id = mult_rs[i].ins_id;
            ll dest_reg = ins[ins_id].fi;
            F_reg_values[dest_reg] = result;
            F_reg_status[dest_reg].Qi = -1;
            for (ll j = 1; j <= num_add; j++) {
                if (add_rs[j].Qj == i + num_load + num_add) {
                    add_rs[j].Vj = result;
                    add_rs[j].Qj = -1;
                    add_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qj with " << result << endl;
                }
                if (add_rs[j].Qk == i + num_load + num_add) {
                    add_rs[j].Vk = result;
                    add_rs[j].Qk = -1;
                    add_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated ADD station " << j << " Qk with " << result << endl;
                }
            }
            for (ll j = 1; j <= num_mult; j++) {
                if (mult_rs[j].Qj == i + num_load + num_add) {
                    mult_rs[j].Vj = result;
                    mult_rs[j].Qj = -1;
                    mult_status[j][2] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qj with " << result << endl;
                }
                if (mult_rs[j].Qk == i + num_load + num_add) {
                    mult_rs[j].Vk = result;
                    mult_rs[j].Qk = -1;
                    mult_status[j][3] = to_string(result);
                    cout << "Cycle " << CLOCK << ": Updated MULT station " << j << " Qk with " << result << endl;
                }
            }
            ins[ins_id].write = CLOCK;
            board[ins_id][3] = CLOCK;
            ins[ins_id].written = true;
            mult_rs[i].Busy = false;
            cdb_busy = true;
            register_results[dest_reg] = "";
            mult_status[i][0] = "No";
            mult_status[i][1] = "";
            mult_status[i][2] = "";
            mult_status[i][3] = "";
            mult_status[i][4] = "";
            cout << "Cycle " << CLOCK << ": Wrote back MULT station " << i << ", ins_id=" << ins_id
                 << ", result=" << result << ", dest_reg=F" << dest_reg << endl;
            return;
        }
    }
}

// 打印指令状态
void print_board() {
    cout << "-------------------------------------------------------\n";
    cout << "|                 Instruction Status                  |\n";
    cout << "|Instruction j    k    Issue Compl(Exec) Result(Write)|\n";
    for (ll i = 1; i <= cnt; i++) {
        cout << "|";
        cout << left << setw(5) << opt_ll_to_opt(ins[i].opt) << " ";
        if (ins[i].opt == 1) {
            cout << "F" << ins[i].fi << ", " << ins[i].fj << "(R" << ins[i].fk << ") ";
        } else {
            cout << "F" << ins[i].fi << ", F" << ins[i].fj << ", F" << ins[i].fk;
        }
        cout << string(11 - (ins[i].opt == 1 ? 7 : 9), ' ');
        for (ll j = 1; j <= 3; j++) {
            cout << right << setw(7) << (board[i][j] == -1 ? "" : to_string(board[i][j])) << "   ";
            if (j == 3) cout << "  |\n";
        }
    }
    cout << "------------------------------------------------------\n";
}

// 打印加载缓冲区状态
void print_load_status() {
    cout << "------------------------------------------------\n";
    cout << "|                 Load  Status                  |\n";
    cout << "|Load    Busy          Address         Val      |\n";
    for (ll i = 1; i <= num_load; i++) {
        cout << "|load" << i << "  " << setw(8) << left << load_status[i][0]
             << setw(15) << load_status[i][1] << setw(10) << load_status[i][2] << "|\n";
    }
    cout << "------------------------------------------------\n";
}

// 打印保留站状态
void print_reservation_stations() {
    cout << "---------------------------------------------------------------------\n";
    cout << "|                      Reservation   Stations                       |\n";
    cout << "|Time   Name  Busy  Op   Vj(S1)    Vk(S2)     Qj(R1)    Qk(R2)      |\n";
    for (ll i = 1; i <= num_add; i++) {
        cout << "|" << setw(4) << add_rs[i].time_remaining << "  add" << i << " "
             << setw(6) << add_status[i][0] << setw(6) << add_status[i][1]
             << setw(10) << add_status[i][2] << setw(10) << add_status[i][3]
             << setw(10) << " " << setw(10) << " " << "|\n";
    }
    for (ll i = 1; i <= num_mult; i++) {
        cout << "|" << setw(4) << mult_rs[i].time_remaining << "  mult" << i << " "
             << setw(6) << mult_status[i][0] << setw(6) << mult_status[i][1]
             << setw(10) << mult_status[i][2] << setw(10) << mult_status[i][3]
             << setw(10) << " " << setw(10) << " " << "|\n";
    }
    cout << "---------------------------------------------------------------------\n";
}

// 打印寄存器状态
void print_register_result_status() {
    cout << "-------------------------------------------------\n";
    cout << "|            Register Result Status CLOCK=" << setw(3) << CLOCK << "          |\n";
    cout << "|F0      F2      F4      F6      F8      F10     |\n";
    cout << "|";
    for (ll i = 0; i <= 10; i += 2) {
        cout << setw(9) << register_results[i];
    }
    cout << "|\n";
    cout << "|F12     F14     F16     F18     F20     F22     |\n";
    cout << "|";
    for (ll i = 12; i <= 22; i += 2) {
        cout << setw(9) << register_results[i];
    }
    cout << "|\n";
    cout << "|F24     F26     F28     F30                     |\n";
    cout << "|";
    for (ll i = 24; i <= 30; i += 2) {
        cout << setw(9) << register_results[i];
    }
    cout << "                  |\n";
    cout << "--------------------------------------------------------\n";
}

// 检查是否所有指令完成
bool all_instructions_completed() {
    for (ll i = 1; i <= cnt; i++) {
        if (!ins[i].written) return false;
    }
    return true;
}

// 运行 Tomasulo 算法
void run_tomasulo() {
    ll next_issue = 1;
    while (!all_instructions_completed() && CLOCK <= MAX_CLOCK) {
        cdb_busy = false;
        write_back();
        execute();
        if (next_issue <= cnt) {
            if (issue_instruction(next_issue)) {
                next_issue++;
            }
        }
        cout << "Cycle " << CLOCK << ":\n";
        print_board();
        print_load_status();
        print_reservation_stations();
        print_register_result_status();
        cout << endl;
        CLOCK++;
    }
    cout << "Simulation completed in " << CLOCK - 1 << " cycles\n";
    cout << "Final Instruction Status:\n";
    print_board();
    cout << "\nFinal Load Buffer Status:\n";
    print_load_status();
    cout << "\nFinal Reservation Station Status:\n";
    print_reservation_stations();
    cout << "\nFinal Register Result Status:\n";
    print_register_result_status();
}
ll opt_string_to_ll(string s)
{
	if(s=="load") return 1;
	else if(s=="store") return 2;
	else if(s=="add.d") return 3;
	else if(s=="sub.d") return 4;
	else if(s=="mul.d") return 5;
	else if(s=="div.d") return 6;
	return -1;
}
ll f_register_string_to_ll(string s)
{
	if(s[0]=='F') 
	{
		ll pos=-1;
		for(ll i=0;i<=30;i=i+2)
		{
			if(f_register_name[i]==s) pos=i;
		}
		return pos;
	}
	return -1;
}
ll r_register_string_to_ll(string s)
{
	if(s[0]=='R')
	{
		ll pos=-1;
		for(ll i=0;i<=31;i++)
		{
			if(r_register_name[i]==s) pos=i;
		}
		return pos;
	}
	return -1;
}
int main() {
    /*n = 6;
    num_load = 3;
    num_add = 3;
    num_mult = 2;
    time_load = 2;
    time_add = 2;
    time_mult = 10;
    time_div = 40;*/
    cin>>n>>num_load>>num_add>>num_mult>>time_load>>time_add>>time_mult>>time_div;
    for(ll i=0;i<=999;i++)    memory[i]=i*1.0;
    F_reg_values[3]=200.0; // R3
    F_reg_values[4]=300.0; // R4
    F_reg_values[8]=0.0;   // F8
    init();
    /*cnt = 6;
    ins[1].opt = 1; ins[1].fi = 6;  ins[1].fj = 21; ins[1].fk = 3;  // L.D F6, 21(R3)
    ins[2].opt = 1; ins[2].fi = 4;  ins[2].fj = 16; ins[2].fk = 4;  // L.D F4, 16(R4)
    ins[3].opt = 5; ins[3].fi = 2;  ins[3].fj = 4;  ins[3].fk = 6;  // MUL.D F2, F4, F6
    ins[4].opt = 4; ins[4].fi = 10; ins[4].fj = 8;  ins[4].fk = 4;  // SUB.D F10, F8, F4
    ins[5].opt = 6; ins[5].fi = 12; ins[5].fj = 2;  ins[5].fk = 6;  // DIV.D F12, F2, F6
    ins[6].opt = 3; ins[6].fi = 8;  ins[6].fj = 10; ins[6].fk = 4;  // ADD.D F8, F10, F4*/
    cnt=0;
    while(1)
	{
		string s;
		cin>>s;
		if(opt_string_to_ll(s)==-1)
		{
			cout<<"error input again";
			continue;
		}
		if(opt_string_to_ll(s)==1)
		{
			ll num;
			string fi,rr;
			cin>>fi>>num>>rr;
			if(f_register_string_to_ll(fi)==-1||num<0||num>99||r_register_string_to_ll(rr)==-1)
			{
				cout<<f_register_string_to_ll(fi)<<"    "<<num<<"     "<<r_register_string_to_ll(rr)<<"\n";
				cout<<"error input again！";
				continue;
			}
			cnt++;
			ins[cnt].opt=opt_string_to_ll(s);
			ins[cnt].fi=f_register_string_to_ll(fi);
			ins[cnt].fj=num;
			ins[cnt].fk=r_register_string_to_ll(rr);
		}
		else
		{
			string fi,fj,fk;
			cin>>fi>>fj>>fk;
			if(f_register_string_to_ll(fi)==-1||f_register_string_to_ll(fj)==-1||f_register_string_to_ll(fk)==-1)
			{
				cout<<"error input again！";
				continue;
			}
			cnt++;
			ins[cnt].opt=opt_string_to_ll(s);
			ins[cnt].fi=f_register_string_to_ll(fi);
			ins[cnt].fj=f_register_string_to_ll(fj);
			ins[cnt].fk=f_register_string_to_ll(fk);
		}	
	//	cout<<ins[cnt].opt<<"\n";
		if(cnt==n) break;
	}
    for(ll i=1;i<=cnt;i++) 
	{
        ins[i].issue=-1;
        ins[i].exec=-1;
        ins[i].write=-1;
        ins[i].issued=false;
        ins[i].executed=false;
        ins[i].written=false;
        for(ll j=1;j<=3;j++) board[i][j] = -1;
    }
    run_tomasulo();
    return 0;
}

/*
6
3 3 2
2 2 10 40
load F6 21 R3
load F4 16 R4
mul.d F2 F4 F6
sub.d F10 F8 F4
div.d F12 F2 F6
add.d F8 F10 F4
*/

/*
6
2 2 2
1 2 10 40
load F6 34 R2
load F2 45 R3
add.d F8 F6 F2
mul.d F4 F2 F6
sub.d F8 F4 F2
add.d F4 F2 F6
*/

/*
6
3 3 2
2 2 10 40
load F6 34 R2
load F2 45 R3
add.d F8 F6 F2
mul.d F4 F2 F6
sub.d F8 F4 F2
add.d F4 F2 F6
*/
