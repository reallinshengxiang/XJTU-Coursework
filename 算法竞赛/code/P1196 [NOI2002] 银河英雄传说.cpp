#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e4+10;
ll f[N],sum[N],front[N],i,j,T;
char ch;
ll find_set(ll x)
{
	if(f[x]==x) return f[x];
	ll fa=find_set(f[x]);
	front[x]=front[x]+front[f[x]];
	f[x]=fa;
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	front[x]=front[x]+sum[y];
	sum[y]=sum[y]+sum[x];	
	f[x]=y;
	sum[x]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=N-1;i++) f[i]=i,sum[i]=1;
	cin>>T;
	while(T--)
	{
		cin>>ch>>i>>j;
		if(ch=='M') merge(i,j);		
		else if(ch=='C')
		{
			ll x=find_set(i);
			ll y=find_set(j);
			if(x!=y) cout<<"-1\n";
			else cout<<abs(front[i]-front[j])-1<<"\n";
		}
	}
	return 0;
}
