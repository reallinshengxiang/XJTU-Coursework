#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll n,m,c,ansi,ansj,maxs=-0x7f7f7f7f7f7f7f,s,a[N][N],sum[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>c;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	for(ll i=c;i<=n;i++)
	{
		for(ll j=c;j<=m;j++)
		{
			s=sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c];
			if(s>maxs) ansi=i-c+1,ansj=j-c+1,maxs=s;
		}
	}
	cout<<ansi<<" "<<ansj;
	return 0;
}
