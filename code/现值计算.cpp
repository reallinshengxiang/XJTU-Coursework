#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
double ans,x,t,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>t;
	t=1+t;
	for(ll i=0;i<=n;i++)
	{
		cin>>x;
		m=pow(t,-i);
		ans=ans+x*m;
	}
	cout<<ans;
	return 0;
}
