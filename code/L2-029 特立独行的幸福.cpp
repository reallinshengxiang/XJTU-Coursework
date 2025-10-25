#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll l,r,x,flag,cnt,prime[N];
vector<ll> e;
map<ll,ll> mp,vis,ff,num;
ll nex(ll xx)
{
	ll ans=0;
	while(xx!=0)
	{
		ans=ans+(xx%10)*(xx%10);
		xx=xx/10;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>r;
	for(ll i=l;i<=r;i++)
	{
		x=i;
		flag=0;
		for(ll j=2;j<=sqrt(x);j++)
		{
			if(x%j==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag) prime[x]=1;
	}
	for(ll i=l;i<=r;i++)
	{
		x=i;
		e.clear();
		mp.clear();
		mp[x]=1;
		ff[x]=1;
		cnt=0;
		while(x!=1)
		{
			x=nex(x);
			e.push_back(x);
			cnt++;
			if(mp[x]) break;
			mp[x]=1;
		}
		if(x!=1) ff[i]=0;
		if(x==1)
		{
			for(ll j=0;j<e.size();j++) vis[e[j]]=1;
			if(prime[i]) cnt=cnt*2;
			num[i]=cnt;
		}
	}
	flag=1;
	for(ll i=l;i<=r;i++)
	{
		if(vis[i]) continue;
		if(!ff[i]) continue;
		flag=0;
		cout<<i<<" "<<num[i]<<"\n";
	}
	if(flag) cout<<"SAD\n";
	return 0;
}
