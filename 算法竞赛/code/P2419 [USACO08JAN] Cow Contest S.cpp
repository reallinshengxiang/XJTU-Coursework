#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans,f[110][110],flag,a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>a>>b;
		f[a][b]=1;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) f[i][j]=max(f[i][j],f[i][k]&f[k][j]);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		flag=1;
		for(ll j=1;j<=n;j++)
		{
			if(i==j) continue;
			flag=flag&(f[i][j]|f[j][i]);
		}
		ans=ans+flag;
	}
	cout<<ans;
	return 0;
}
