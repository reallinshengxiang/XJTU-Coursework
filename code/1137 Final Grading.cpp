#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ll N=1e5+10;
struct grade{
	string id;
	ll Gp=-1,Gmt=-1,Gf=-1,G=-1,flag;
};
grade gg[N];
string s;
ll g,p,n,m,cnt;
map<string,ll> vis;
bool cmp(grade x,grade y)
{
	if(x.G>y.G) return 1;
	if(x.G==y.G&&x.id<y.id) return 1;
	return 0; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p>>m>>n;
	for(ll i=1;i<=p;i++)
	{
		cin>>s>>g;
		if(!vis[s])
		{
			cnt++;
			vis[s]=cnt;
		}
		gg[vis[s]].id=s;
		gg[vis[s]].Gp=g;	
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>s>>g;
		if(!vis[s])
		{
			cnt++;
			vis[s]=cnt;
		}
		gg[vis[s]].id=s;
		gg[vis[s]].Gmt=g;	
	}
	for(ll i=1;i<=n;i++)
	{
		cin>>s>>g;
		if(!vis[s])
		{
			cnt++;
			vis[s]=cnt;
		}
		gg[vis[s]].id=s;
		gg[vis[s]].Gf=g;	
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(gg[i].Gmt>gg[i].Gf) gg[i].G=gg[i].Gmt*4+gg[i].Gf*6;
		else gg[i].G=gg[i].Gf*10;
		if(gg[i].Gp<200) gg[i].flag=-1;
		if(gg[i].G%10>=5) gg[i].G=gg[i].G/10+1;
		else gg[i].G=gg[i].G/10;
		if(gg[i].Gf<60) gg[i].flag=-1;
	}
	sort(gg+1,gg+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++)
	{
		if(gg[i].flag==-1) continue;
		cout<<gg[i].id<<" "<<gg[i].Gp<<" "<<gg[i].Gmt<<" "<<gg[i].Gf<<" "<<gg[i].G<<"\n";
	}
	return 0;
}
