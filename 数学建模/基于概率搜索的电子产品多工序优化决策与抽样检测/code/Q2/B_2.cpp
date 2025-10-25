#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
struct LPJ{
	ld num,cpl,gmdj,jccb,ifc=0;  //个数，次品率，购买单价，检测成本 
}; //零配件
LPJ P1,P2;
ld CP_cpl,CP_zpcb,CP_jccb,CP_scsj,DHSS,CJFY; 
int num;
struct CP{
	ld num,cpl,p1_num,p1_cpl,p2_num,p2_cpl; //个数，次品率，成品中p1的个数、次品率，成品中p2的个数、次品率  
}; //成品
struct Path{
	int step;
	int choice;
};
Path path[100010],bestpath[100010];
ld bestans=0;
int h,besth;
ld besti,bestj;
void search(LPJ p1,LPJ p2,CP c,ld cb,ld lr,ll step);
void print(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	cout<<"p1:"<<fixed<<setprecision(4)<<p1.num<<"   "<<p1.cpl<<"  "<<p1.gmdj<<"  "<<p1.jccb<<"\n";
	cout<<"p2:"<<fixed<<setprecision(4)<<p2.num<<"   "<<p2.cpl<<"  "<<p2.gmdj<<"  "<<p2.jccb<<"\n";
	cout<<"CP:"<<fixed<<setprecision(4)<<c.num<<"   "<<c.cpl<<"  "<<c.p1_cpl<<"  "<<c.p1_num<<"  "<<c.p2_cpl<<"  "<<c.p2_num<<"\n";
}
void step1_test_all(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	cb=cb+p1.num*p1.jccb+p2.num*p2.jccb;
	p1.num=p1.num*(1-p1.cpl);
	p2.num=p2.num*(1-p2.cpl);
	p1.ifc=1;
	p2.ifc=1;
	p1.cpl=p2.cpl=0;
	
	search(p1,p2,c,cb,lr,2);
}
void step1_test_p1(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	cb=cb+p1.num*p1.jccb;
	p1.num=p1.num*(1-p1.cpl);
	p1.ifc=1;
	p1.cpl=0;
	
	search(p1,p2,c,cb,lr,2);
}
void step1_test_p2(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	cb=cb+p1.num*p2.jccb;
	p2.num=p2.num*(1-p2.cpl);
	p2.ifc=1;
	p2.cpl=0;
	
	search(p1,p2,c,cb,lr,2);
}
void step1_test_no(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	search(p1,p2,c,cb,lr,2);
}
void step2_test1(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	c.cpl=(c.cpl*c.num+min(p1.num,p2.num)*(1-(1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl)))/(c.num+min(p1.num,p2.num));
	c.p1_cpl=(c.p1_cpl*c.p1_num+min(p1.num,p2.num)*p1.cpl)/(c.p1_num+min(p1.num,p2.num));
	c.p2_cpl=(c.p2_cpl*c.p2_num+min(p1.num,p2.num)*p2.cpl)/(c.p2_num+min(p1.num,p2.num));
	c.p1_num=c.p1_num+min(p1.num,p2.num);
	c.p2_num=c.p2_num+min(p1.num,p2.num);
	c.num=c.num+min(p1.num,p2.num);
	ld pp=min(p1.num,p2.num);
	p1.num=p1.num-pp;
	p2.num=p2.num-pp;
	lr=lr+CP_scsj*c.num;
	search(p1,p2,c,cb,lr,4);
}
void step2_test2(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	c.cpl=(c.cpl*c.num+min(p1.num,p2.num)*(1-(1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl)))/(c.num+min(p1.num,p2.num));
	c.p1_cpl=(c.p1_cpl*c.p1_num)/(c.p1_num+min(p1.num,p2.num)*(1-p1.cpl)*(1-p2.cpl));
	c.p2_cpl=(c.p2_cpl*c.p2_num)/(c.p2_num+min(p1.num,p2.num)*(1-p1.cpl)*(1-p2.cpl));
	c.p1_num=c.p1_num+min(p1.num,p2.num)*(1-p1.cpl)*(1-p2.cpl);
	c.p2_num=c.p2_num+min(p1.num,p2.num)*(1-p1.cpl)*(1-p2.cpl);
	c.num=c.num+min(p1.num,p2.num);
	ld pp=min(p1.num,p2.num)*(1-p1.cpl)*(1-p2.cpl);
	p1.num=p1.num-pp;
	p2.num=p2.num-pp;
	lr=lr+CP_scsj*c.num*(1-c.cpl);
	cb+=c.num*CP_jccb;
	c.num=c.num*c.cpl;
	c.cpl=1;
	search(p1,p2,c,cb,lr,3);
}
void step3_test1(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	// cout<<"step3_test1\n"; 
	c.num=c.num*(1-c.cpl);
	c.cpl=0;
	c.p1_num=c.p2_num=c.num;
	c.p1_cpl=c.p2_cpl=0;	
	if(lr-cb>bestans)
	{
		bestans=lr-cb;
		besth=h;
		besti=p1.cpl,bestj=p2.cpl;
		for(int i=1;i<=besth;i++)
		{
			bestpath[i]=path[i];
		}
	}
	if(p1.cpl!=0&&p2.cpl!=0) 
	{
		cout<<p1.cpl<<" "<<p2.cpl<<endl;
	 num++;
	// cout<<num;
	cout<<"p end"<<p1.cpl<<" "<<p2.cpl<<endl;
	cout<<"path:"<<endl;
	for(int i=1;i<=h;i++)
	{ 
		cout<<"("<<path[i].step<<","<<path[i].choice<<") ";
	}
	cout<<"ans: "<<lr-cb<<endl;
	//_sleep(100);
	}
	cb=lr=0;
	return;
}
void step3_test2(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	// print(p1,p2,c,cb,lr);
	cb=cb+c.num*(c.cpl)*CJFY;
	p1.num+=c.num*(1-c.cpl);
	p2.num+=c.num*(1-c.cpl);
	c.num=c.num*(1-c.cpl);
	c.cpl=0;
	c.p1_num=c.p2_num=c.num;
	c.p1_cpl=c.p2_cpl=0;
	// cout<<"ctmd"<<p1.num<<" "<<p2.num;
	c.num=0;
	search(p1,p2,c,cb,lr,1);
}
void step4_test(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	cb=cb+c.num*c.cpl*(DHSS+CP_scsj);
	c.num=c.num*c.cpl;
	p1.num+=c.num;
	p2.num+=c.num;
	c.cpl=1;
	c.p1_num=c.p2_num=c.num;
	
	c.p1_cpl=c.p2_cpl=0;
	search(p1,p2,c,cb,lr,3);
}
ll check(LPJ p1,LPJ p2,CP c,ld cb,ld lr)
{
	// cout<<p1.ifc<<"  "<<p2.ifc<<"\n";
	ld x=(1-p1.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p1.ifc)*(1-CP_cpl))*DHSS)-CJFY;
	ld y=(1-p2.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p2.ifc)*(1-CP_cpl))*DHSS)-CJFY;
	ld z=(1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl))*DHSS)-CJFY;
	if(p1.ifc&&p2.ifc) {
		return 1; 
	}
	else if(p2.ifc){
		if((1-p1.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p1.ifc)*(1-CP_cpl))*DHSS)-CJFY>0) return 0;
		else return 1;
	}
	else if(p1.ifc){
		
		if((1-p2.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p2.ifc)*(1-CP_cpl))*DHSS)-CJFY>0) return 0;
		else return 1;
	}
	else {
		if((1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl)*CP_scsj-6-min(CP_jccb,(1-(1-p1.cpl)*(1-p2.cpl)*(1-CP_cpl))*DHSS)-CJFY>0)return 0;
		else return 1;
	}
	return 0;
}
void search(LPJ p1,LPJ p2,CP c,ld cb,ld lr,ll step)
{
	// cout<<step<<"\n";
	ld ccbb=cb,llrr=lr;
	//print(p1,p2,c,cb,lr);
	if(step==1)
	{
		if(!p1.ifc&&!p2.ifc)
		{
			path[++h].step=1;
			path[h].choice=1;
			step1_test_all(p1,p2,c,cb,lr);
			h--;
		}
		if(!p1.ifc)
		{
			path[++h].step=1;
			path[h].choice=2;
			step1_test_p1(p1,p2,c,cb,lr);
			h--;
		}
		if(!p2.ifc)
		{
			path[++h].step=1;
			path[h].choice=3;
			step1_test_p2(p1,p2,c,cb,lr);
			h--;
		}
		path[++h].step=1;
		path[h].choice=4;
		step1_test_no(p1,p2,c,cb,lr);
		h--;
	}
	else if(step==2)
	{
		path[++h].step=2;
		path[h].choice=1;
		step2_test1(p1,p2,c,cb,lr);  //不检测 
		h--;
		path[++h].step=2;
		path[h].choice=2;
		step2_test2(p1,p2,c,cb,lr);  //检测 
		h--;
	}
	else if(step==3)
	{
		if(p1.ifc==1&&p2.ifc==1)
		{
			if(CP_scsj*(1-CP_cpl)>CP_zpcb+CJFY)
			{
				cb+=c.num*c.cpl*(CP_zpcb+(CP_zpcb+CJFY)*CP_cpl/((1-CP_cpl)*(1-CP_cpl)));
				lr+=c.cpl*c.num*CP_scsj;
			}
			p1.num=0,p2.num=0;
			
		}
		if(check(p1,p2,c,cb,lr)||h>=50) 
		{
			path[++h].step=3;
			path[h].choice=1;
			step3_test1(p1,p2,c,cb,lr);  //不拆解 
			h--;
		}
		else {
			path[++h].step=3;
			path[h].choice=2;
			step3_test2(p1,p2,c,cb,lr);  //拆解 
			h--;
		}
	} 
	else if(step==4)
	{
		path[++h].step=4;
		path[h].choice=1;
		step4_test(p1,p2,c,cb,lr);
		h--;
	}
}
int main()
{
	
	freopen("out.txt","w",stdout);
	cin>>P1.cpl>>P1.gmdj>>P1.jccb>>P2.cpl>>P2.gmdj>>P2.jccb>>CP_cpl>>CP_zpcb>>CP_jccb>>CP_scsj>>DHSS>>CJFY;
	CP c;
	P1.num=1;
	P2.num=1;
	c.num=c.cpl=c.p1_cpl=c.p1_num=c.p2_cpl=c.p2_num=0;
	search(P1,P2,c,P1.num*P1.gmdj+P2.num*P2.gmdj,0,1);
	cout<<"path:"<<endl;
	for(int i=1;i<=besth;i++)
	{ 
		cout<<bestpath[i].step<<" "<<bestpath[i].choice<<" ";
	}
	cout<<"ans: "<<bestans<<endl;
	cout<<"besth"<<besth<<endl;
	// cout<<"besti,j"<<besti<<" "<<bestj;
	return 0;
}