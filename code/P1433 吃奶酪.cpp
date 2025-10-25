#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double x,y;
};
point p[22];
double dis[22][22],dp[22][1<<16],ans;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	p[0].x=p[0].y=0;
	for(ll i=0;i<=n;i++)
	{
		for(ll j=i;j<=n;j++) dis[i][j]=dis[j][i]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
	}	
	memset(dp,127,sizeof(dp));
	ans=dp[0][0];
	dp[0][0]=0;
	for(ll i=1;i<=n;i++) dp[i][1<<(i-1)]=dis[0][i];
	for(ll k=1;k<=(1<<n)-1;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			if((k&(1<<(i-1)))==0) continue;
			for(ll j=1;j<=n;j++)
			{
				if(i==j) continue;
				if((k&(1<<(j-1)))==0) continue;
				dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
