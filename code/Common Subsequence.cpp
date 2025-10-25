#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
ll dp[5010][5010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s1>>s2)
	{
		memset(dp,0,sizeof(dp));
	 	for(ll i=0;i<=s1.size()-1;i++)
	 	{
	 		for(ll j=0;j<=s2.size()-1;j++)
			{
			 	if(s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j]+1;
			 	else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			} 
		}
		cout<<dp[s1.size()][s2.size()]<<"\n";
	}
	return 0;
} 
