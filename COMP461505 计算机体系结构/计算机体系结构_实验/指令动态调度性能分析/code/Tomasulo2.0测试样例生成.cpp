#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,num_load,num_store,num_add,num_mult,time_load,time_store,time_add,time_sub,time_mult,time_div;
int main() 
{
    srand(time(0));
    n=rand()%10+1;
    num_load=rand()%6;
    num_store=rand()%6; 
    num_add=rand()%6;
    num_mult=rand()%6;
    time_load=rand()%5+1;
    time_store=rand()%5+1;
    time_add=rand()%10+1;
    time_sub=time_add;
    time_mult=rand()%20+1;
    time_div=rand()%50+1; 
    cout<<n<<"\n";
    vector<string> f_regs;
    for(ll i=0;i<=30;i+=2) f_regs.push_back("F"+to_string(i));
    vector<string> r_regs={"R1","R2","R3","R4"};
    vector<string> recent_f_regs={"F6","F2","F8"};
    vector<string> recent_r_regs={"R2","R3"};
    ll total_weight=num_load+num_store+num_add+num_mult;
    if(total_weight == 0) 
	{
        total_weight=1;
        if(num_load==0) 
		{
			num_load=1;
			num_store=1;
			num_add=1;
			num_mult=1;
            total_weight=4;
        }
    }
	cout<<num_load<<" "<<num_store<<" "<<num_add<<" "<<num_mult<<"\n"<<time_load<<" "<<time_store<<" "<<time_add<<" "<<time_mult<<" "<<time_div<<"\n";
    for(ll i=0;i<n;i++) 
	{
        string instr;
        ll r=rand()%total_weight;
        ll temp=r;
        if(temp<num_load) 
		{
            instr="load";
        } 
		else 
		{
            temp=temp-num_load;
            if(temp<num_store) 
			{
                instr="store";
            } 
			else 
			{
                temp=temp-num_store;
                if(temp<num_add) 
				{
                    if(rand()%2==0) instr="add.d";
                    else instr="sub.d";
                } 
				else 
				{
                    temp=temp-num_add;
                    if(rand()%2==0) instr="mul.d";
                    else instr ="div.d";
                }
            }
        }
        string output;
        if(instr=="load"||instr=="store") 
		{
		    string f_reg;
		    if(rand()%2&&!recent_f_regs.empty())  f_reg=recent_f_regs[rand()%recent_f_regs.size()];
			else  f_reg=f_regs[rand()%f_regs.size()];
		    string r_reg;
		    if(rand()%2&&!recent_r_regs.empty())  r_reg=recent_r_regs[rand()%recent_r_regs.size()];
			else  r_reg=r_regs[rand()%r_regs.size()];
		    ll offset=rand()%100;
		    output=instr+" "+f_reg+" "+to_string(offset)+" "+r_reg;
		    recent_f_regs.push_back(f_reg);
		    recent_r_regs.push_back(r_reg);		    
		    if(recent_f_regs.size()>3) recent_f_regs.erase(recent_f_regs.begin());
		    if(recent_r_regs.size()>3) recent_r_regs.erase(recent_r_regs.begin());
		} 
		else
		{
		    string f_dest;
		    if(rand()%2&&!recent_f_regs.empty())  f_dest=recent_f_regs[rand()%recent_f_regs.size()];
		    else f_dest=f_regs[rand()%f_regs.size()];
		    string f_src1;
		    if(rand()%2&&!recent_f_regs.empty())  f_src1=recent_f_regs[rand()%recent_f_regs.size()];
		    else  f_src1=f_regs[rand()%f_regs.size()];
		    string f_src2;
		    if(rand()% 2&&!recent_f_regs.empty()) f_src2=recent_f_regs[rand()%recent_f_regs.size()];
		    else  f_src2=f_regs[rand()%f_regs.size()];
		    output=instr+" "+f_dest+" "+f_src1+" "+f_src2;
		    recent_f_regs.push_back(f_dest);
		    recent_f_regs.push_back(f_src1);
		    recent_f_regs.push_back(f_src2);
		    if(recent_f_regs.size()>3) recent_f_regs.erase(recent_f_regs.begin());
		}
        cout<<output<<"\n";
    }
    return 0;
}
