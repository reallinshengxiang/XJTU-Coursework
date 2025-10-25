#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll dp[N][N],len;
char a[N],b[N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size(); 
	for(ll i=1;i<=len;i++)
	{
		a[i]=s[i-1];
		b[i]=s[len-i];
	}
	for(ll i=1;i<=len;i++) cout<<a[i];
	cout<<"\n";
	for(ll i=1;i<=len;i++) cout<<b[i];
	cout<<"\n";
	for(ll i=1;i<=len;i++)
	{
		for(ll j=1;j<=len;j++)
		{
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<len-dp[len][len];
	return 0;
}
