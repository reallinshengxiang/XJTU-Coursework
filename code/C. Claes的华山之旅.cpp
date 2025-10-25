#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,n,k,x,qq,f[1010],p[1010],q[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>x>>qq;
	for(ll i=1;i<=n;i++) cin>>p[i]>>q[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=k;j>=p[i];j--) f[j]=max(f[j],f[j-p[i]]+q[i]);
	}
	ans=f[k];
	memset(f,0,sizeof(f));
	for(ll i=x;i<=n;i++)
	{
		for(ll j=k;j>=p[i];j--) f[j]=max(f[j],f[j-p[i]]+q[i]);
	}
	ans=max(ans,f[k]+qq);
	cout<<ans;
	return 0;
}
