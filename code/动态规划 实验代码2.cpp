#include<bits/stdc++.h>
using namespace std;
void MinCost(int L,int n,int *p)
{
	int inf=0x7fffffff,**dp=new int *[n+2];
	for(int i=0;i<=n+1;i++) dp[i]=new int[n+2]; 
	sort(p,p+n+1);
	for(int i=n+1;i>=1;i--) p[i]=p[i]-p[i-1];
	for(int i=1;i<=n+1;i++) p[i]=p[i]+p[i-1];
	for(int i=1;i<=n+1;i++) dp[i][i]=0;
	for(int len=2;len<=n+1;len++)
	{
		for(int i=1;i<=n+1-len+1;i++)
		{
			int j=i+len-1;
			dp[i][j]=inf;
			for(int k=i;k<=j-1;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[j]-p[i-1]);
		}
	}
	cout<<dp[1][n+1];
}
int main()
{
	int L,n,*p;
    cin>>L>>n;
    p=new int[n+2];
    p[0]=0;
    p[n+1]=L;
    for(int i=1;i<n+1;i++) cin>>p[i];
    MinCost(L,n,p);
	return 0;
}





