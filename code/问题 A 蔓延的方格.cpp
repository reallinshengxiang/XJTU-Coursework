#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll ans,t,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>x;
		ans=(2*(x%mod)*((x+1)%mod)+1)%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
