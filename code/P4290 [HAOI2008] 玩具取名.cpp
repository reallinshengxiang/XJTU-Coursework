#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a,b;
map<char,ll> mp;
ll num[6],flag[6][6][6],dp[220][220][6];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp['W']=1,mp['I']=2,mp['N']=3,mp['G']=4;
	for(ll i=1;i<=4;i++) cin>>num[i];
	for(ll i=1;i<=4;i++)
	{
		for(ll j=1;j<=num[i];j++) cin>>a>>b,flag[i][mp[a]][mp[b]]=1;
	}
	cin>>s;
	ll n=s.size();
	for(ll i=1;i<=n;i++) dp[i][i][mp[s[i-1]]]=1;
	for(ll len=2;len<=n;len++)
	{
		for(ll st=1;st+len-1<=n;st++)
		{
			ll ed=st+len-1;
			for(ll k=st;k<ed;k++)
			{
				for(ll x=1;x<=4;x++)
				{
					for(ll y=1;y<=4;y++)
					{
						for(ll z=1;z<=4;z++)
						{
							if(dp[st][k][y]&&dp[k+1][ed][z]&&flag[x][y][z]) dp[st][ed][x]=1;
						}
					}
				}
			}
		}
	}
	ll ff=0;
    if(dp[1][n][1]) cout<<"W",ff=1;
    if(dp[1][n][2]) cout<<"I",ff=1;
    if(dp[1][n][3]) cout<<"N",ff=1;
    if(dp[1][n][4]) cout<<"G",ff=1;
    if(!ff) cout<<"The name is wrong!";
	return 0;
}
