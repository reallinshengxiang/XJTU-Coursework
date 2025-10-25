#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll n,ans,m,a[N],b[N],p[N][N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1; i<=n; i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	for(ll i=1; i<=n; i++)
	{
		cin>>b[i];
		m=max(m,b[i]);
	}
	ans=n*m;
	p[0][0][0]=1; 
	for(ll k=1; k<=n; k++)
	{
		for(ll i=0; i<=n*m; i++)
		{
			for(ll j=0; j<=n*m; j++)
			{
				if(i-a[k]>=0) p[i][j][k]=p[i-a[k]][j][k-1];
				if(j-b[k]>=0) p[i][j][k]=p[i][j][k]|p[i][j-b[k]][k-1];
			}
		}
	}
    for(ll i=1;i<=n*m;i++)
    {
    	for(ll j=1;j<=n*m;j++)
    	{
    		if(p[i][j][n]) ans=min(ans,max(i,j));
		}
	}
	cout<<ans;
	return 0;
}
