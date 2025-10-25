#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=20210509+10;
ll f[N],x,ans,n;
ll dfs(ll x)
{
	if(f[x]!=0) return f[x];
	if(x==1) 
	{
		f[1]=1;
		return 1;
	}
	for(ll i=1;i<=sqrt(x);i++)
	{
		if(x%i==0) 
		{
			f[x]=f[x]+dfs(i);
			if(i*i!=x&&i!=1) f[x]=f[x]+dfs(x/i);
		}
	}
	return f[x];
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) ans=ans+dfs(i),cout<<i<<" "<<ans<<"\n";
	cout<<"\n";
	cout<<ans;
	return 0;
}
