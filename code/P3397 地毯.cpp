#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e3+10;
ll d[N][N],sum[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x1,x2,y1,y2,n,m;
	cin>>n>>m;
	while(m--)
	{
		cin>>x1>>y1>>x2>>y2;
		d[x1][y1]++;
		d[x2+1][y1]--;
		d[x1][y2+1]--;
		d[x2+1][y2+1]++;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			sum[i][j]=d[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			cout<<sum[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
