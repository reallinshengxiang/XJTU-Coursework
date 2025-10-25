#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5;
double dp[N+10];
ll T,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1]=0;
	for(ll i=2;i<=N;i++)
	{
		double cnt=0,sum=0;
		for(ll j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				sum=sum+dp[j];
				cnt++;
				if(i/j!=j) 
				{
					sum=sum+dp[i/j];
					cnt++;
				}
			}
			dp[i]=(sum/cnt+1)*cnt/(cnt-1);
		}
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<fixed<<setprecision(4)<<dp[n]<<"\n";
	}
	return 0;
}
