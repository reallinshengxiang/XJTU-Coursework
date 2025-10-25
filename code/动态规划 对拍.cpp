#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
map<int,int> mp;
int dp[N][N],p[N];
int solve(int l,int r,int *p)
{
	if(dp[l][r]!=0) return dp[l][r];
	if(l==r)
	{
		dp[l][r]=0;
		return 0;
	}
	int ans=0x7fffffff;
	for(int i=l; i<=r-1; i++) ans=min(solve(l,i,p)+solve(i+1,r,p)+p[r]-p[l-1],ans);
	dp[l][r]=ans;
	return ans;
}
int MinCost1(int L,int n,int *p)
{
	memset(dp,0,sizeof(dp));
	int ans=solve(1,n+1,p);
	return ans;
}
int MinCost2(int L,int n,int *p)
{
	int inf=0x7fffffff,**dp=new int *[n+2];
	for(int i=0; i<=n+1; i++) dp[i]=new int[n+2];
	for(int i=1; i<=n+1; i++) dp[i][i]=0;
	for(int len=2; len<=n+1; len++)
	{
		for(int i=1; i<=n+1-len+1; i++)
		{
			int j=i+len-1;
			dp[i][j]=inf;
			for(int k=i; k<=j-1; k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[j]-p[i-1]);
		}
	}
	return dp[1][n+1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,L,cnt=0,T,flag=1;
	cin>>T;
	while(T--)
	{
		srand(time(0));
		n=rand()%100;
		L=rand()%1000;
		mp.clear();
		for(int i=1; i<=n; i++)
		{
			p[i]=rand()%(L+1);
			if(mp[p[i]]||p[i]==0) i--;
			mp[p[i]]=1;
		}
		p[0]=0;
		p[n+1]=L;
		sort(p,p+n+1);
		for(int i=n+1; i>=1; i--) p[i]=p[i]-p[i-1];
		for(int i=1; i<=n+1; i++) p[i]=p[i]+p[i-1];
		int ans2=MinCost2(L,n,p);
		int ans1=MinCost1(L,n,p);
		if(ans1!=ans2)
		{
			flag=0;
			cout<<"Wrong Answer!\n"<<ans1<<"   "<<ans2<<"\n";
			cout<<L<<" "<<n<<"\n";
			for(int i=1; i<=n; i++) cout<<p[i]<<" ";
			break;
		}
	}
	if(flag) cout<<"Accepted!\n";
	return 0;
}





