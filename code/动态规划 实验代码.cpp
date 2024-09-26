#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int dp[N][N];
int solve(int l,int r,int *p)
{
	if(dp[l][r]!=0) return dp[l][r];
	if(l==r) 
	{
		dp[l][r]=0;
		return 0;
	}
	int ans=0x7fffffff;	
	for(int i=l;i<=r-1;i++) ans=min(solve(l,i,p)+solve(i+1,r,p)+p[r]-p[l-1],ans);
	dp[l][r]=ans;
	return ans;
}
void MinCost(int L,int n,int *p)
{
	sort(p,p+n+1);
	for(int i=n+1;i>=1;i--) p[i]=p[i]-p[i-1];
	for(int i=1;i<=n+1;i++) p[i]=p[i]+p[i-1];
	int ans=solve(1,n+1,p);
	cout<<ans; 
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




