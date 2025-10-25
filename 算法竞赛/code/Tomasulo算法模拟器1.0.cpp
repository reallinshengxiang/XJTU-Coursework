#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110,MAX_CLOCK=110;
struct instruction{
    ll opt,fi,fj,fk; 
    ll issue=-1,exec=-1,write=-1; 
    bool issued=false,executed=false,written=false;
};
struct ReservationStation{
    bool Busy=false;
    string Op;
    double Vj=0,Vk=0; 
    ll Qj=-1,Qk=-1; 
    ll A=0; 
    ll time_remaining=0; 
    ll ins_id=-1; 
    double result=0; 
    string Qj_source,Qk_source; 
    ll ready_cycle=-1; 
};
struct RegisterStatus{
    ll Qi=-1; 
    double value=0; 
};
instruction ins[N];
ll n,num_load,num_add,num_mult,cnt,time_load,time_store,time_add,time_mult,time_div,CLOCK=1;
ll board[N][5],history_board[MAX_CLOCK][N][5]; 
string load_status[10][10],add_status[10][10],mult_status[10][10],register_results[33];
string history_load_status[MAX_CLOCK][10][10],history_add_status[MAX_CLOCK][10][10],history_mult_status[MAX_CLOCK][10][10],history_register_results[MAX_CLOCK][33];
string f_register_name[33], r_register_name[33];
vector<ReservationStation> add_rs,mult_rs,load_buffers;
RegisterStatus F_reg_status[32];
double F_reg_values[32];
double memory[1000]={0};
bool cdb_busy=false;
string opt_ll_to_opt(ll x) 
{
    if(x==1) return "load";
    else if(x==2) return "store";
    else if(x==3) return "add.d";
    else if(x==4) return "sub.d";
    else if(x==5) return "mul.d";
    else return "div.d";
}
void init() 
{
    for (ll i=0;i<=31;i++) 
    {
        r_register_name[i]="R"+to_string(i);
        f_register_name[i]="F"+to_string(i);
    }
    add_rs.resize(num_add+1);
    mult_rs.resize(num_mult+1);
    load_buffers.resize(num_load+1);
    for(ll i=1;i<=num_load;i++) 
    {
        load_status[i][0]="No";
        load_status[i][1]="";
        load_status[i][2]="";
    }
    for(ll i=1;i<=num_add;i++) 
    {
        add_status[i][0]="No";
        add_status[i][1]="";
        add_status[i][2]="";
        add_status[i][3]="";
        add_status[i][4]="";
    }
    for(ll i=1;i<=num_mult;i++) 
    {
        mult_status[i][0]="No";
        mult_status[i][1]="";
        mult_status[i][2]="";
        mult_status[i][3]="";
        mult_status[i][4]="";
    }
    for(ll i=0;i<32;i++) 
    {
        F_reg_values[i]=0.0;
        register_results[i]="";
    }
}
bool issue_instruction(ll ins_id) 
{
    instruction &inst=ins[ins_id];
    if(inst.issued) return false;
    if(inst.opt==1) 
    { 
        for(ll i=1;i<=num_load;i++) 
        {
            if(!load_buffers[i].Busy) 
            {
                load_buffers[i].Busy=true;
                load_buffers[i].Op="LOAD";
                load_buffers[i].ins_id=ins_id;
                load_buffers[i].ready_cycle=-1;
                load_buffers[i].time_remaining=time_load;
                if(F_reg_status[inst.fk].Qi==-1) 
                {
                    load_buffers[i].Vj=F_reg_values[inst.fk];
                    load_buffers[i].Qj=-1;
                } 
                else
                {
                    load_buffers[i].Qj=F_reg_status[inst.fk].Qi;
                    if(F_reg_status[inst.fk].Qi<=num_load)   load_buffers[i].Qj_source="Load"+to_string(F_reg_status[inst.fk].Qi);
                    else if(F_reg_status[inst.fk].Qi<=num_load+num_add) load_buffers[i].Qj_source="Add"+to_string(F_reg_status[inst.fk].Qi-num_load);
                    else load_buffers[i].Qj_source="Mult"+to_string(F_reg_status[inst.fk].Qi-num_load-num_add);
                }
                load_buffers[i].A=inst.fj;
                F_reg_status[inst.fi].Qi=i;
                inst.issue=CLOCK;
                board[ins_id][1]=CLOCK;
                inst.issued=true;
                load_status[i][0]="Yes";
                load_status[i][1]=to_string(inst.fj)+"(R"+to_string(inst.fk)+")";
                register_results[inst.fi]="Load"+to_string(i);
                cout<<"Cycle "<<CLOCK<<": Issued LOAD ins_id="<<ins_id<<", buffer="<<i<<", Vj="<<load_buffers[i].Vj<<", Qj="<<load_buffers[i].Qj<<", A="<<load_buffers[i].A<<"\n";
                return 1;
            }
        }
    } 
    else if(inst.opt==3||inst.opt==4) 
    { 
        for(ll i=1;i<=num_add;i++) 
        {
            if(!add_rs[i].Busy) 
            {
                add_rs[i].Busy=true;
                add_rs[i].ready_cycle=-1;
                add_rs[i].time_remaining=0;
                if(inst.opt==3)  add_rs[i].Op="ADD.D";
                else  add_rs[i].Op="SUB.D";
                add_rs[i].ins_id = ins_id;
                if(F_reg_status[inst.fj].Qi==-1) 
                {
                    add_rs[i].Vj=F_reg_values[inst.fj];
                    add_rs[i].Qj=-1;
                } 
                else 
                {
                    add_rs[i].Qj=F_reg_status[inst.fj].Qi;
                    if(F_reg_status[inst.fj].Qi<=num_load)  add_rs[i].Qj_source="Load"+to_string(F_reg_status[inst.fj].Qi); 
                    else if(F_reg_status[inst.fj].Qi<=num_load+num_add)  add_rs[i].Qj_source="Add"+to_string(F_reg_status[inst.fj].Qi-num_load);
                    else add_rs[i].Qj_source="Mult"+to_string(F_reg_status[inst.fj].Qi-num_load-num_add);
                }
                if(F_reg_status[inst.fk].Qi==-1) 
                {
                    add_rs[i].Vk=F_reg_values[inst.fk];
                    add_rs[i].Qk=-1;
                } 
                else 
                {
                    add_rs[i].Qk=F_reg_status[inst.fk].Qi;
                    if(F_reg_status[inst.fk].Qi<=num_load) add_rs[i].Qk_source="Load"+to_string(F_reg_status[inst.fk].Qi);
                    else if(F_reg_status[inst.fk].Qi<=num_load+num_add)  add_rs[i].Qk_source="Add"+to_string(F_reg_status[inst.fk].Qi-num_load);
                    else add_rs[i].Qk_source="Mult"+to_string(F_reg_status[inst.fk].Qi-num_load-num_add);
                }
                F_reg_status[inst.fi].Qi=i+num_load;
                inst.issue=CLOCK;
                board[ins_id][1]=CLOCK;
                inst.issued=true;
                add_status[i][0]="Yes";
                add_status[i][1]=add_rs[i].Op;
                if(add_rs[i].Qj==-1)  
				{
					add_status[i][2]=to_string(add_rs[i].Vj);
					add_status[i][4]="";
				}
                else  
				{
					add_status[i][2]="";
					add_status[i][4]=add_rs[i].Qj_source;
				}
                if(add_rs[i].Qk==-1)  
				{
					add_status[i][3]=to_string(add_rs[i].Vk);
					add_status[i][5]="";
				}
                else  
				{
					add_status[i][3]="";
					add_status[i][5]=add_rs[i].Qk_source;
				}
                register_results[inst.fi]="Add"+to_string(i);
                cout<<"Cycle "<<CLOCK<<": Issued "<<add_rs[i].Op<<" ins_id="<<ins_id<<", add_rs="<<i<<", Vj="<<add_rs[i].Vj<<", Qj="<<add_rs[i].Qj<<", Vk="<<add_rs[i].Vk<<", Qk="<<add_rs[i].Qk<<"\n";
				return 1;
            }
        }
    } 
    else if(inst.opt==5||inst.opt==6) 
    { 
        for(ll i=1;i<=num_mult;i++) 
        {
            if(!mult_rs[i].Busy) 
            {
                mult_rs[i].Busy=true;
                mult_rs[i].ready_cycle = -1;
                mult_rs[i].time_remaining = 0;
                if(inst.opt==5)  mult_rs[i].Op="MULT.D";
                else mult_rs[i].Op="DIV.D";
                mult_rs[i].ins_id=ins_id;
                if(F_reg_status[inst.fj].Qi==-1)
                {
                    mult_rs[i].Vj=F_reg_values[inst.fj];
                    mult_rs[i].Qj=-1;
                } 
                else
                {
                    mult_rs[i].Qj=F_reg_status[inst.fj].Qi;
                    if(F_reg_status[inst.fj].Qi<=num_load)  mult_rs[i].Qj_source="Load"+to_string(F_reg_status[inst.fj].Qi);
                    else if(F_reg_status[inst.fj].Qi<=num_load+num_add) mult_rs[i].Qj_source="Add"+to_string(F_reg_status[inst.fj].Qi-num_load);
                    else  mult_rs[i].Qj_source="Mult"+to_string(F_reg_status[inst.fj].Qi-num_load-num_add);
                }
                if(F_reg_status[inst.fk].Qi==-1) 
                {
                    mult_rs[i].Vk=F_reg_values[inst.fk];
                    mult_rs[i].Qk=-1;
                } 
                else
                {
                    mult_rs[i].Qk=F_reg_status[inst.fk].Qi;
                    if(F_reg_status[inst.fk].Qi<=num_load) mult_rs[i].Qk_source="Load"+to_string(F_reg_status[inst.fk].Qi);
                    else if(F_reg_status[inst.fk].Qi<=num_load+num_add)  mult_rs[i].Qk_source="Add"+to_string(F_reg_status[inst.fk].Qi-num_load);
                    else  mult_rs[i].Qk_source="Mult"+to_string(F_reg_status[inst.fk].Qi-num_load-num_add);
                }
                F_reg_status[inst.fi].Qi=i+num_load+num_add;
                inst.issue=CLOCK;
                board[ins_id][1]=CLOCK;
                inst.issued=true;
                mult_status[i][0]="Yes";
                mult_status[i][1]=mult_rs[i].Op;
                if(mult_rs[i].Qj==-1)  
				{
					mult_status[i][2]=to_string(mult_rs[i].Vj);
					mult_status[i][4]="";
				}
                else  
				{
					mult_status[i][2]="";
					mult_status[i][4]=mult_rs[i].Qj_source;
				}
                if(mult_rs[i].Qk==-1)  
				{
					mult_status[i][3]=to_string(mult_rs[i].Vk);
					mult_status[i][5]="";
				}
                else  
				{
					mult_status[i][3]="";
					mult_status[i][5]=mult_rs[i].Qk_source;
				}
				register_results[inst.fi]="Mult"+to_string(i);
                cout<<"Cycle "<<CLOCK<<": Issued "<<mult_rs[i].Op<<" ins_id="<<ins_id<<", mult_rs="<<i<<", Vj="<<mult_rs[i].Vj<<", Qj="<<mult_rs[i].Qj<<", Vk="<<mult_rs[i].Vk<<", Qk="<<mult_rs[i].Qk<<"\n";
                return 1;
            }
        }
    }
    return 0;
}
void execute() 
{
    for(ll i=1;i<=num_load;i++) 
    {
    	if(CLOCK==board[load_buffers[i].ins_id][1]) continue;
        if(load_buffers[i].Busy&&load_buffers[i].Qj==-1&&load_buffers[i].time_remaining>0) 
        {
            load_buffers[i].time_remaining--;
            register_results[ins[load_buffers[i].ins_id].fi]="Load"+to_string(i);
            if(load_buffers[i].time_remaining==0)
            {
                ll address=(ll)(load_buffers[i].Vj+load_buffers[i].A);
                load_buffers[i].result=memory[address];
                ll ins_id=load_buffers[i].ins_id;
                ins[ins_id].exec=CLOCK;
                board[ins_id][2]=CLOCK;
                ins[ins_id].executed=true;
                load_status[i][4]="M"+to_string(i);
                cout<<"Cycle "<<CLOCK<<": LOAD buffer "<<i<<" completed, ins_id="<<ins_id;
                cout<<", address="<<address<<", result="<<memory[address]<<"\n";
            } 
            else  cout<<"Cycle "<<CLOCK<<": LOAD buffer "<<i<<" executing, time_remaining="<<load_buffers[i].time_remaining<<"\n";
        }
    }
    for(ll i=1;i<=num_add;i++) 
    {
        ReservationStation &rs=add_rs[i];
        if(CLOCK==board[rs.ins_id][1]) continue;
        if(rs.Busy&&rs.Qj==-1&&rs.Qk==-1) 
        {
            if(rs.ready_cycle==-1) 
            {
                rs.ready_cycle=CLOCK;
                rs.time_remaining=time_add;
            }
            if(rs.ready_cycle!=-1&&CLOCK>=rs.ready_cycle) 
            {
                if(rs.time_remaining>0) 
                {
                    rs.time_remaining--;
                    register_results[ins[rs.ins_id].fi]="Add"+to_string(i);
                    if(rs.time_remaining==0) 
                    {
                        if(rs.Op=="ADD.D") rs.result=rs.Vj+rs.Vk;
                        else  rs.result=rs.Vj-rs.Vk;
                        ll ins_id=rs.ins_id;
                        ins[ins_id].exec=CLOCK;
                        board[ins_id][2]=CLOCK;
                        ins[ins_id].executed=true;
                        add_status[i][4]="M"+to_string(i+num_load);
                        cout<<"Cycle "<<CLOCK<<": ADD station "<<i<<" completed, ins_id="<<ins_id<<", result="<<rs.result<<"\n";
                    } 
                    else  cout<<"Cycle "<<CLOCK<<": ADD station "<<i<<" executing, time_remaining="<<rs.time_remaining<<"\n";
                }
            }
        }
    }
    for(ll i=1;i<=num_mult;i++) 
    {
        ReservationStation &rs=mult_rs[i];
        if(CLOCK==board[rs.ins_id][1]) continue;
        if(rs.Busy&&rs.Qj==-1&&rs.Qk==-1) 
        {
            if(rs.ready_cycle==-1) 
            {
                rs.ready_cycle=CLOCK;
                if(rs.Op=="MULT.D")  rs.time_remaining=time_mult;
                else  rs.time_remaining=time_div;
            }
            if(rs.ready_cycle!=-1&&CLOCK>=rs.ready_cycle) 
            {
                if(rs.time_remaining>0) 
                {
                    rs.time_remaining--;
                    register_results[ins[rs.ins_id].fi]="Mult"+to_string(i);
                    if(rs.time_remaining==0) 
                    {
                        if(rs.Op=="MULT.D")  rs.result=rs.Vj*rs.Vk;
                        else  rs.result=rs.Vj/rs.Vk;
                        ll ins_id=rs.ins_id;
                        ins[ins_id].exec=CLOCK;
                        board[ins_id][2]=CLOCK;
                        ins[ins_id].executed=true;
                        mult_status[i][4]="M"+to_string(i+num_load+num_add);
                        cout<<"Cycle "<<CLOCK<<": MULT station "<<i<<" completed, ins_id="<<ins_id<<", result="<<rs.result<<"\n";
                    } 
                    else   cout<<"Cycle "<<CLOCK<<": MULT station "<<i<<" executing, time_remaining="<<rs.time_remaining<<"\n";
                }
            }
        }
    }
}
void write_back() 
{
    for(ll i=1;i<=num_load;i++) 
    {
    	if(CLOCK==board[load_buffers[i].ins_id][2]) continue;
        if(load_buffers[i].Busy&&load_buffers[i].time_remaining==0&&ins[load_buffers[i].ins_id].executed&&!cdb_busy) 
        {
            double result=load_buffers[i].result;
            ll ins_id=load_buffers[i].ins_id;
            ll dest_reg=ins[ins_id].fi;
            F_reg_values[dest_reg]=result;
            F_reg_status[dest_reg].Qi=-1;
            for(ll j=1;j<=num_add;j++) 
            {
                if(add_rs[j].Qj==i) 
                {
                    add_rs[j].Vj=result;
                    add_rs[j].Qj=-1;
                    add_status[j][2]=to_string(result);
                    add_status[j][4]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qj with "<<result<<"\n";
                }
                if (add_rs[j].Qk==i) 
                {
                    add_rs[j].Vk=result;
                    add_rs[j].Qk=-1;
                    add_status[j][3]=to_string(result);
                    add_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            for(ll j=1;j<=num_mult;j++) 
            {
                if(mult_rs[j].Qj==i) 
                {
                    mult_rs[j].Vj=result;
                    mult_rs[j].Qj=-1;
                    mult_status[j][2]=to_string(result);
                    mult_status[j][4]=""; 
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qj with "<<result<<"\n";
                }
                if (mult_rs[j].Qk==i) 
                {
                    mult_rs[j].Vk=result;
                    mult_rs[j].Qk=-1;
                    mult_status[j][3]=to_string(result);
                    mult_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            ins[ins_id].write=CLOCK;
            board[ins_id][3]=CLOCK;
            ins[ins_id].written=true;
            load_buffers[i].Busy=false;
            cdb_busy=true;
            register_results[dest_reg]="";
            load_status[i][0]="No";
            load_status[i][1]="";
            load_status[i][2]="";
            cout<<"Cycle "<<CLOCK<<": Wrote back LOAD buffer "<<i<<", ins_id="<<ins_id<<", result="<<result<<", dest_reg=F"<<dest_reg<<"\n";
            return;
        }
    }
    for(ll i=1;i<=num_add;i++) 
    {
    	if(CLOCK==board[add_rs[i].ins_id][2]) continue;
        if(add_rs[i].Busy&&add_rs[i].time_remaining==0&&ins[add_rs[i].ins_id].executed&&!cdb_busy) 
        {
            double result=add_rs[i].result;
            ll ins_id=add_rs[i].ins_id;
            ll dest_reg=ins[ins_id].fi;
            F_reg_values[dest_reg]=result;
            F_reg_status[dest_reg].Qi=-1;
            for (ll j=1;j<=num_add;j++) 
            {
                if(add_rs[j].Qj==i+num_load) 
                {
                    add_rs[j].Vj=result;
                    add_rs[j].Qj=-1;
                    add_status[j][2]=to_string(result);
                    add_status[j][4]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qj with "<<result<<"\n";
                }
                if(add_rs[j].Qk==i+num_load) 
                {
                    add_rs[j].Vk=result;
                    add_rs[j].Qk=-1;
                    add_status[j][3]=to_string(result);
                    add_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            for (ll j=1;j<=num_mult;j++) 
            {
                if(mult_rs[j].Qj==i+num_load) 
                {
                    mult_rs[j].Vj=result;
                    mult_rs[j].Qj=-1;
                    mult_status[j][2]=to_string(result);
                    mult_status[j][4]="";
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qj with "<<result<<"\n";
                }
                if(mult_rs[j].Qk==i+num_load) 
                {
                    mult_rs[j].Vk=result;
                    mult_rs[j].Qk=-1;
                    mult_status[j][3]=to_string(result);
                    mult_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            ins[ins_id].write=CLOCK;
            board[ins_id][3]=CLOCK;
            ins[ins_id].written=true;
            add_rs[i].Busy=false;
            cdb_busy=true;
            register_results[dest_reg]="";
            add_status[i][0]="No";
            add_status[i][1]="";
            add_status[i][2]="";
            add_status[i][3]="";
            add_status[i][4]="";
            cout<<"Cycle "<<CLOCK<<": Wrote back ADD station "<<i<<", ins_id="<<ins_id<<", result="<<result<<", dest_reg=F"<<dest_reg<<"\n";
            return;
        }
    }
    for(ll i=1;i<=num_mult;i++) 
    {
    	if(CLOCK==board[mult_rs[i].ins_id][2]) continue;
        if(mult_rs[i].Busy&&mult_rs[i].time_remaining==0&&ins[mult_rs[i].ins_id].executed&&!cdb_busy) 
        {
            double result=mult_rs[i].result;
            ll ins_id=mult_rs[i].ins_id;
            ll dest_reg=ins[ins_id].fi;
            F_reg_values[dest_reg]=result;
            F_reg_status[dest_reg].Qi=-1;
            for(ll j=1;j<=num_add;j++) 
            {
                if(add_rs[j].Qj==i+num_load+num_add) 
                {
                    add_rs[j].Vj=result;
                    add_rs[j].Qj=-1;
                    add_status[j][2]=to_string(result);
                    add_status[j][4]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qj with "<<result<<"\n";
                }
                if(add_rs[j].Qk==i+num_load+num_add) 
                {
                    add_rs[j].Vk=result;
                    add_rs[j].Qk=-1;
                    add_status[j][3]=to_string(result);
                    add_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated ADD station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            for(ll j=1;j<=num_mult;j++)
            {
                if(mult_rs[j].Qj==i+num_load+num_add) 
                {
                    mult_rs[j].Vj=result;
                    mult_rs[j].Qj=-1;
                    mult_status[j][2]=to_string(result);
                    mult_status[j][4]="";
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qj with "<<result<<"\n";
                }
                if(mult_rs[j].Qk==i+num_load+num_add) 
                {
                    mult_rs[j].Vk=result;
                    mult_rs[j].Qk=-1;
                    mult_status[j][3]=to_string(result);
                    mult_status[j][5]="";
                    cout<<"Cycle "<<CLOCK<<": Updated MULT station "<<j<<" Qk with "<<result<<"\n";
                }
            }
            ins[ins_id].write=CLOCK;
            board[ins_id][3]=CLOCK;
            ins[ins_id].written=true;
            mult_rs[i].Busy=false;
            cdb_busy=true;
            register_results[dest_reg]="";
            mult_status[i][0]="No";
            mult_status[i][1]="";
            mult_status[i][2]="";
            mult_status[i][3]="";
            mult_status[i][4]="";
            cout<<"Cycle "<<CLOCK<<": Wrote back MULT station "<<i<<", ins_id="<<ins_id<<", result="<<result<<", dest_reg=F"<<dest_reg<<"\n";
            return;
        }
    }
}
void print_board() 
{
    cout<<"------------------------------------------------------\n";
    cout<<"|                 Instruction Status                 |\n";
    cout<<"|Instruction j  k     Issue Compl(Exec) Result(Write)|\n";
    for(ll i=1;i<=cnt;i++) 
    {
        cout<<"|";
        cout<<left<<setw(5)<<opt_ll_to_opt(ins[i].opt)<<" ";
		if(ins[i].opt==1)  cout<<left<<setw(13)<<("F"+to_string(ins[i].fi)+", "+to_string(ins[i].fj)+"(R"+to_string(ins[i].fk)+") ");
        else  cout<<left<<setw(13)<<("F"+to_string(ins[i].fi)+", F"+to_string(ins[i].fj)+", F"+to_string(ins[i].fk));
        for(ll j=1;j<=3;j++) 
        {
            if(board[i][j]==-1) cout<<right<<setw(7)<<""<<"   ";
			else cout<<right<<setw(7)<<to_string(board[i][j])<<"   ";
            if(j==3) cout<<"   |\n";
        }
    }
    cout<<"------------------------------------------------------\n";
}
void print_load_status() 
{
    cout<<"----------------------------\n";
    cout<<"|     Load  Status         |\n";
    cout<<"|Load   Busy     Address   |\n";
    for(ll i=1;i<=num_load;i++) 
	{
		string name="load"+to_string(i);
        cout<<"|"<<left<<setw(6)<<name<<" "<<setw(5)<<left<<load_status[i][0]<<"    "<<setw(10)<<load_status[i][1]<<"|\n";
    }
   cout<<"----------------------------\n";
}
void print_reservation_stations() 
{
    cout<<"----------------------------------------------------------------------\n";
    cout<<"|                         Reservation   Stations                     |\n";
    cout<<"|Time   Name   Busy    Op      Vj(S1)      Vk(S2)      Qj(R1)  Qk(R2)|\n";
    for(ll i=1;i<=num_add;i++) 
    {
        string name="add"+to_string(i);
        cout<<"|"<<right<<setw(3)<<add_rs[i].time_remaining<<"   "<<setw(5)<<name<<" ";
        cout<<setw(6)<<add_status[i][0]<<"  "<<setw(6)<<add_status[i][1];
        cout<<setw(12)<<add_status[i][2]<<setw(12)<<add_status[i][3]<<"  ";
    	cout<<setw(8)<<add_status[i][4]<<setw(8)<<add_status[i][5]<< "|\n";
    }
    for(ll i=1;i<=num_mult;i++) 
    {
        string name="mult"+to_string(i);
        cout<<"|"<<right<<setw(3)<<mult_rs[i].time_remaining<<"   "<<setw(5)<<name<<" ";
        cout<<setw(6)<<mult_status[i][0]<<"  "<<setw(6)<<mult_status[i][1];
        cout<<setw(12)<<mult_status[i][2]<<setw(12)<<mult_status[i][3]<<"  ";
    	cout<<setw(8)<<mult_status[i][4]<<setw(8)<<mult_status[i][5]<< "|\n";
    }
    cout<<"----------------------------------------------------------------------\n";
}
void print_register_result_status() 
{
    cout<<"--------------------------------------------------------\n";
    cout<<"|           Register Result Status CLOCK="<<setw(3)<<CLOCK<<"           |\n";
    cout<<"|F0       F2       F4       F6       F8       F10      |\n";
    cout<<"|";
    for(ll i=0;i<=10;i=i+2)  cout<<left<<setw(9)<<register_results[i];
    cout<<"|\n";
    cout<<"|F12      F14      F16      F18      F20      F22      |\n";
    cout<<"|";
    for(ll i=12;i<=22;i=i+2) cout<<left<<setw(9)<<register_results[i];
    cout<<"|\n";
    cout<<"|F24      F26      F28      F30                        |\n";
    cout<<"|";
    for(ll i=24;i<=30;i=i+2) cout<<left<<setw(9)<<register_results[i];
    cout<<"                  |\n";
    cout<<"--------------------------------------------------------\n";
}
bool all_instructions_completed() 
{
    for(ll i=1;i<=cnt;i++) 
    {
        if(!ins[i].written) return 0;
    }
    return 1;
}
void update_history(ll tt)
{
    for(ll i=0;i<=N-1;i++)
    {
        for(ll j=0;j<=4;j++) history_board[tt][i][j]=board[i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=2;j++) history_load_status[tt][i][j]=load_status[i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=9;j++) history_add_status[tt][i][j]=add_status[i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=9;j++) history_mult_status[tt][i][j]=mult_status[i][j];
    }
    for(ll i=0;i<=32;i++) history_register_results[tt][i]=register_results[i];
}
void write_history_back(ll tt)
{
    for(ll i=0;i<=N-1;i++)
    {
        for(ll j=0;j<=4;j++) board[i][j]=history_board[tt][i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=2;j++) load_status[i][j]=history_load_status[tt][i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=9;j++) add_status[i][j]=history_add_status[tt][i][j];
    }
    for(ll i=0;i<=9;i++)
    {
        for(ll j=0;j<=9;j++) mult_status[i][j]=history_mult_status[tt][i][j];
    }
    for(ll i=0;i<=32;i++) register_results[i]=history_register_results[tt][i];
}
void run_tomasulo() 
{
    ll next_issue=1;
    while(!all_instructions_completed()&&CLOCK<=MAX_CLOCK) 
    {
        cdb_busy=false;
        if(next_issue<=cnt) 
        {
            if(issue_instruction(next_issue))  next_issue++;
        }
		execute();
		write_back();
        cout<<"Cycle "<<CLOCK<<":\n";
        print_board();
        print_load_status();
        print_reservation_stations();
        print_register_result_status();
        cout<<"\n";
        update_history(CLOCK);
        CLOCK++;
    }
    CLOCK--;
    cout<<"Simulation completed in "<<CLOCK<<" cycles\n";
    cout<<"Final Instruction Status:\n";
    print_board();
    cout<<"\nFinal Load Buffer Status:\n";
    print_load_status();
    cout<<"\nFinal Reservation Station Status:\n";
    print_reservation_stations();
    cout<<"\nFinal Register Result Status:\n";
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
void calculate_performance() 
{
    ll total_cycles=min(CLOCK,MAX_CLOCK);
    ll sequential_cycles=0;
    for(ll i=1;i<=n;i++)
    {
    	if(ins[i].opt==1||ins[i].opt==2) sequential_cycles=sequential_cycles+2+time_load;
    	else if(ins[i].opt==3||ins[i].opt==4)  sequential_cycles=sequential_cycles+2+time_add;
    	else if(ins[i].opt==5)  sequential_cycles=sequential_cycles+2+time_mult;
    	else if(ins[i].opt==6)  sequential_cycles=sequential_cycles+2+time_div;
	}
    double speedup=(double)sequential_cycles/total_cycles;
    double throughput=(double)n/total_cycles;
    double efficiency=speedup/n;
    cout<<"================ Performance Analysis ================\n";
    cout<<"Total Execution Cycles: "<<total_cycles<<"\n";
    cout<<"Sequential Execution Cycles: "<<sequential_cycles<<"\n";
    cout<<fixed<<setprecision(2);
    cout<<"Speedup: "<<speedup<<"\n";
    cout<<"Throughput (instructions/cycle): "<<throughput<<"\n";
    cout<<"Efficiency: "<<efficiency<<"\n";
    cout<<"======================================================\n";
}
void check_history()
{
	ll tt=0;
	while(1)
	{
        cout<<"你想要查看那个时刻的状态? 1<=time<="<<min(CLOCK,MAX_CLOCK)<<"           当前时刻为:"<<tt<<"\n";
        cout<<"A.当前时刻前一时刻\nB.当前时刻后一时刻\nC.当前时刻前N时刻\nD.当前时刻后N时刻\nE.指定具体时刻\nQ.退出\n";
		char ch;
		ll N;
		cin>>ch;
		if(!(ch=='A'||ch=='B'||ch=='C'||ch=='D'||ch=='E'||ch=='Q'))
		{
			cout<<"输入错误,请重新输入(A/B/C/D/E/Q)\n";
			continue;
		} 
		if(ch=='A') tt=max((ll)0,tt-1);
		else if(ch=='B') tt=min(min(MAX_CLOCK,CLOCK),tt+1);
		else if(ch=='C')
		{
			cout<<"输入N（0~"<<tt<<"):";
			cin>>N; 
			tt=tt-N;
		} 
		else if(ch=='D')
		{
			cout<<"输入N（0~"<<min(MAX_CLOCK,CLOCK)-tt<<"):";
			cin>>N; 
			tt=tt+N;
		}
		else if(ch=='E') 
		{
			cout<<"输入具体时刻（1~"<<min(CLOCK,MAX_CLOCK)<<"):"; 
		    cin>>tt;
		}
		else if(ch=='Q') return;
        write_history_back(tt);
        cout<<"Cycle "<<tt<<":\n";
        print_board();
        print_load_status();
        print_reservation_stations();
        print_register_result_status();
        cout<<"\n";
	}	
}
int main() 
{
    cout<<"--------------------------------------------Tomasulo 算法模拟器-----------------------------------------------\n";
    cout<<"Tomasulo算法核心思想是：记录和检测指令相关，操作数一旦就绪就立即执行，把发生RAW（写后读）冲突的可能性减少到最少。通过寄存器换名来消除WAR（读后写）和WAW（写后写）冲突。\n";
    cout<<"Tomasulo算法模拟器支持两种不同方式的输入：\n输入1  实行交互式输入（推荐）\n输入2  实行简略输入\n";
    ll input_opt;
	cin>>input_opt;
	if(input_opt==1)
	{
	    cout<<"指令数 n （请输入数字）：";
		cin>>n;
		cout<<"LOAD部件数量 num_load （请输入数字）：";
		cin>>num_load;
		cout<<"ADD 部件数量 num_add  （请输入数字）：";
		cin>>num_add;
		cout<<"MULT部件数量 num_mult （请输入数字）：";
		cin>>num_add;
		cout<<"LOAD/STORE指令延迟时间 time_load （请输入数字）：";
		cin>>time_load; 
		cout<<"ADD/SUB   指令延迟时间 time_add  （请输入数字）：";
		cin>>time_add; 
		cout<<"MULT      指令延迟时间 time_mult （请输入数字）：";
		cin>>time_mult;
		cout<<"DIV       指令延迟时间 time_div  （请输入数字）：";
		cin>>time_div; 		
	}
	else if(input_opt==2)  cin>>n>>num_load>>num_add>>num_mult>>time_load>>time_add>>time_mult>>time_div;
	for(ll i=0;i<=999;i++)    memory[i]=i*1.0;
	for(ll i=1;i<=31;i++)  F_reg_values[i]=i*100.0;
	init();
	cnt=0;
	cout<<"指令输入格式（区分字母大小写）：按照 MIPS 语法，支持 load、store、add.d、sub.d、mul.d、div.d 操作\n";
	cout<<"例如：\nload F6 34 R2\nstore F6 45 R3\nadd.d F8 F6 F2\nmul.d F2 F4 F6\nsub.d F10 F8 F4\ndiv.d F12 F2 F6\n";
	while(1)
	{
		cout<<"请输入第"<<cnt+1<<"条指令："; 
	    string s;
	    cin>>s;
	    if(opt_string_to_ll(s)==-1)
	    {
	        cout<<"输入错误,请重新输入\n";
	        continue;
	    }
	    if(opt_string_to_ll(s)==1||opt_string_to_ll(s)==2)
	    {
	        ll num;
	        string fi,fj,rr;
	        cin>>fi>>fj>>rr;
	        try 
			{
		        num=stoll(fj);
		    } 
			catch(const invalid_argument& e) 
			{
		        num=-1;
		    } 
			catch(const out_of_range& e) 
			{
		        num=-1;
		    }
	        if(f_register_string_to_ll(fi)==-1||num<0||num>99||r_register_string_to_ll(rr)==-1)
	        {
	            cout<<"输入错误,请重新输入\n";
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
	            cout<<"输入错误,请重新输入\n";
	            continue;
	        }
	        cnt++;
	        ins[cnt].opt=opt_string_to_ll(s);
	        ins[cnt].fi=f_register_string_to_ll(fi);
	        ins[cnt].fj=f_register_string_to_ll(fj);
	        ins[cnt].fk=f_register_string_to_ll(fk);
	    }
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
	    for(ll j=1;j<=3;j++) board[i][j]=-1;
	}
	run_tomasulo();
	calculate_performance();
	check_history();
	return 0;
}
/*
6
3 3 2
2 2 10 40
load F6 34 R2
load F2 45 R3
mul.d F0 F2 F4
sub.d F8 F6 F2
div.d F10 F0 F6
add.d F6 F8 F2
*/

/*
6
3 3 2
2 2 10 40
load F8 21 R3
load F4 16 R4
mul.d F2 F4 F6
sub.d F10 F8 F4
div.d F12 F2 F6
add.d F8 F10 F4
*/

/*
6
3 3 2
2 2 10 40
store F8 21 R3
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

/*
10
3 3 2
2 3 4 5
load F6 13 R2
add.d F2 F8 F30
sub.d F6 F8 F24
sub.d F20 F12 F22
mul.d F6 F22 F2
mul.d F26 F14 F0
div.d F18 F8 F28
div.d F6 F26 F12
sub.d F8 F20 F6
div.d F8 F6 F2 
*/

/*
2
18
3 3 2
2 3 4 5
load F14 57 R1
mul.d F2 F2 F10
div.d F10 F14 F2
add.d F10 F2 F14
mul.d F30 F24 F22
store F10 33 R4
sub.d F20 F30 F2
mul.d F20 F30 F18
mul.d F2 F4 F30
add.d F30 F24 F30
add.d F20 F2 F0
mul.d F18 F20 F30
mul.d F18 F30 F20
add.d F24 F16 F30
sub.d F30 F0 F14
sub.d F8 F16 F6
store F4 77 R2
add.d F20 F0 F8*/
