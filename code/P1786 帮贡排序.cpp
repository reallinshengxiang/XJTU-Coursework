#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct man{
	string name;
	ll zhiwei,bg,dj,id;
};
man a[120],b[5];
map<string,ll> mp1;
map<ll,string> mp2;
ll n,p,cnt1,bg,dj,cnt;
string s,name;
bool cmp1(man x,man y)
{
	if(x.bg!=y.bg) return x.bg>y.bg;
	return x.id<y.id;
}
bool cmp(man x,man y)
{
	if(x.zhiwei!=y.zhiwei) return x.zhiwei<y.zhiwei;
	else 
	{
		if(x.dj!=y.dj) return x.dj>y.dj;
		else return x.id<y.id;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp1["BangZhu"]=1;
	mp1["FuBangZhu"]=2;
	mp1["HuFa"]=3;
	mp1["ZhangLao"]=4;
	mp1["TangZhu"]=5;
	mp1["JingYing"]=6;
	mp1["BangZhong"]=7;
	mp2[1]="BangZhu";
	mp2[2]="FuBangZhu";
	mp2[3]="HuFa";
	mp2[4]="ZhangLao";
	mp2[5]="TangZhu";
	mp2[6]="JingYing";
	mp2[7]="BangZhong";
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>name>>s>>bg>>dj;
		if(s=="BangZhu") cout<<name<<" "<<"BangZhu"<<" "<<dj<<"\n";
		else if(s=="FuBangZhu")
		{
			cnt1++;
			b[cnt1].name=name;
			b[cnt1].dj=dj;
			b[cnt1].bg=bg;
		} 
		else
		{
			cnt++;
			a[cnt].name=name;
			a[cnt].zhiwei=mp1[s];
		    a[cnt].id=cnt;
		    a[cnt].bg=bg;
		    a[cnt].dj=dj;
		}		
	}
	if(cnt1==1) cout<<b[cnt1].name<<" "<<"FuBangZhu"<<" "<<b[cnt1].dj<<"\n";
	else if(cnt1==2)
	{
		if(b[1].dj<b[2].dj) swap(b[1],b[2]);
		for(ll i=1;i<=2;i++) cout<<b[i].name<<" "<<"FuBangZhu"<<" "<<b[i].dj<<"\n";
	}
	sort(a+1,a+cnt+1,cmp1);
	for(ll i=1;i<=cnt;i++) 
	{
		if(i>=1&&i<=2) a[i].zhiwei=3;
		else if(i>=3&&i<=6) a[i].zhiwei=4;
		else if(i>=7&&i<=13) a[i].zhiwei=5;
		else if(i>=14&&i<=38) a[i].zhiwei=6;
		else if(i>=39) a[i].zhiwei=7;
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++) 	cout<<a[i].name<<" "<<mp2[a[i].zhiwei]<<" "<<a[i].dj<<"\n";
	return 0;
}
