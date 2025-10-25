#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=12;
ll dp[N],n,len,a,b,maxx;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		len=s.size();
		a=s[0]-'0';
		b=s[len-1]-'0';
		dp[b]=max(dp[b],dp[a]+1);
		maxx=max(maxx,dp[b]);
	}
	cout<<n-maxx;
	return 0;
}
