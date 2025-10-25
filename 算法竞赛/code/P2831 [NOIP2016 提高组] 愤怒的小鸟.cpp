#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps=1e-8;
const ll N=1<<20;
struct point{
	double x,y;
};
point p[20];
ll T,n,m,line[20][20],up[N],dp[N];
void equation(double &x,double &y,double a1,double b1,double c1,double a2,double b2,double c2)
{	
	y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	x=(c1-b1*y)/a1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	for(ll i=0;i<=(1<<18)-1;i++)
	{
		ll j=1;
		while((i&(1<<(j-1)))&&(j<=18)) j++;
		up[i]=j;
	}
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(dp,127,sizeof(dp));
		memset(line,0,sizeof(line));
		dp[0]=0;
		for(ll i=1;i<=n;i++) cin>>p[i].x>>p[i].y;	
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(fabs(p[i].x-p[j].x)<eps) continue;
				double a,b;
				equation(a,b,p[i].x*p[i].x,p[i].x,p[i].y,p[j].x*p[j].x,p[j].x,p[j].y);				
				if(a>-eps) continue;				
				for(ll k=1;k<=n;k++) 
				{
					if(fabs(a*p[k].x*p[k].x+b*p[k].x-p[k].y)<eps) line[i][j]=line[i][j]|(1<<(k-1));
				}
			}
		}		
		for(ll i=0;i<=(1<<n)-1;i++)
		{
			ll j=up[i];
			dp[i|(1<<(j-1))]=min(dp[i|(1<<(j-1))],dp[i]+1);
			for(ll k=1;k<=n;k++) dp[i|line[j][k]]=min(dp[i|line[j][k]],dp[i]+1);
		}	
		cout<<dp[(1<<n)-1]<<"\n";
	}
	return 0;
}
