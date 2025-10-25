#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll f[N],sum[N],down[N],q;
ll find_set(ll x)
{
	if(f[x]!=x)
	{
		ll fa=find_set(f[x]);
		down[x]=down[x]+down[f[x]];
		f[x]=fa;
	}
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	f[x]=y;
	down[x]=down[x]+sum[y];
	sum[y]=sum[y]+sum[x];	
	sum[x]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=N-1;i++) 
	{
		f[i]=i;
		sum[i]=1;
	}
	cin>>q;
	while(q--)
	{
		char ch;
		ll x,y;
		cin>>ch;
		if(ch=='M')
		{
			cin>>x>>y;
			if(find_set(x)!=find_set(y))  merge(x,y);
		}
		else 
		{
			cin>>x;
			find_set(x);
			cout<<down[x]<<"\n";
		}
	}
	return 0;
} 
