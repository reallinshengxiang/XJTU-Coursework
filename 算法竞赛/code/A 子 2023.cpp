#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll len,dp[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2023;i++) s=s+to_string(i);
	len=s.size();
	for(ll i=0;i<=len-1;i++)
	{
		if(s[i]=='2') 
		{
			dp[0]++;
			dp[2]=dp[2]+dp[1];
		}
		else if(s[i]=='0') dp[1]=dp[0]+dp[1];
		else if(s[i]=='3') dp[3]=dp[3]+dp[2];
	}
	cout<<dp[3]; 
	return 0;
} 
//5484660609
