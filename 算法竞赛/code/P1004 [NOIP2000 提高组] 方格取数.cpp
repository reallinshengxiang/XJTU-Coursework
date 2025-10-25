#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=11;
ll n,a,b,c,f[N][N][N][N],w[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(cin>>a>>b>>c)
	{
		if(a==0&&b==0&&c==0) break;
		w[a][b]=c;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=1;k<=n;k++)
			{
				for(ll q=1;q<=n;q++)
				{
					f[i][j][k][q]=max(max(f[i-1][j][k-1][q],f[i-1][j][k][q-1]),max(f[i][j-1][k-1][q],f[i][j-1][k][q-1]))+w[i][j];
					if(i!=1&&j!=q) f[i][j][k][q]=f[i][j][k][q]+w[k][q];
				}
			}
		}
	}
	cout<<f[n][n][n][n];
	return 0;
}
