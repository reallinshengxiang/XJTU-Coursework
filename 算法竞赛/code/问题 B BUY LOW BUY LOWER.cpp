#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> s;
ll a[5050],f[5050],dp[5050],n,maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n+1;i++)
	{
		s.clear();
		maxx=0;
		f[i]=1;
		for(ll j=i-1;j>=1;j--)
		{
			if (a[j]>a[i])
           {
              if(dp[j]>maxx)
              {
                  maxx=dp[j];
                  s.clear();
                  s.insert(a[j]);
                  f[i]=f[j];
              }
               if(dp[j]==maxx&&!s.count(a[j]))
              {
                f[i]=f[i]+f[j];
                s.insert(a[j]);
              }   
           }           
        }
		dp[i]=maxx+1;
	}
	cout<<dp[n+1]-1<<" "<<f[n+1];
	return 0;
}
