#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct waimai{
	ll ts,id;
};
waimai a[N];
bool cmp(waimai a,waimai b)
{
	if(a.id<b.id) return 1;
	if(a.id==b.id&&a.ts<b.ts) return 1;
	return 0; 
}
ll n,m,t,ans,pos[N],cnt,pri,flag,last;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>t;
	for(ll i=1;i<=m;i++) cin>>a[i].ts>>a[i].id;
	sort(a+1,a+m+1,cmp);
	for(ll i=1;i<=m;i++)
	{
		if(!mp[a[i].id])
		{
			mp[a[i].id]=1;
			pos[++cnt]=i;
		}
	}
	pos[cnt+1]=m+1;
	for(ll i=1;i<=cnt;i++)
	{
		pri=0,last=0,flag=0;
		for(ll j=pos[i];j<=pos[i+1]-1;j++)
		{
			if(a[j].ts<=last+1) pri=pri+2;
			else 
			{
				pri=max((ll)0,pri-(a[j].ts-last-1));
				if(pri<=3) flag=0;
				pri=pri+2;
			}			
			last=a[j].ts;
			if(pri>5) flag=1;
		}
		if(a[pos[i+1]-1].ts<t)
		{
			pri=max((ll)0,pri-(t-last));
		    if(pri<=3) flag=0;
		}		
		if(flag) ans++;
	}
	cout<<ans;
	return 0;
}
