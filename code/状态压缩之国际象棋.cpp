#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=(1<<7),mod=1000000007;
ll dp[110][21][N][N],num[N],n,m,k,ans;
ll count(ll x)
{
	ll ans=0;
	while(x!=0)
	{
		ans=ans+(x&1);
		x>>=1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=0;i<(1<<n);i++)
	{
		num[i]=count(i);
		dp[1][num[i]][i][0]=1;
	}
	for(ll i=2;i<=m;i++)
	{
		for(ll j=0;j<(1<<n);j++)
		{
			for(ll d=num[j];d<=k;d++)
			{
				for(ll q=0;q<(1<<n);q++)
				{
					for(ll p=0;p<(1<<n);p++)
					{
						ll x=num[j];
						if(!(j&(q>>2))&&!(j&(q<<2))&&!(j&(p>>1))&&!(j&(p<<1)))	dp[i][d][j][q]=(dp[i-1][d-x][q][p]+dp[i][d][j][q])%mod;
					}
				}
			}
		}
	}
	for(ll i=0;i<(1<<n);i++)
	{
		for(ll j=0;j<(1<<n);j++)	ans=(ans+dp[m][k][i][j])%mod;
	}
	cout<<ans;
	return 0;
} 
