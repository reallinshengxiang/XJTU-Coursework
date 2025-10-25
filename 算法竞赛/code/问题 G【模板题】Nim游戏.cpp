#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>ans;
	for(ll i=2;i<=n;i++)
	{
		cin>>x;
		ans=ans^x;
	}
	if(ans==0) cout<<"No";
	else cout<<"Yes";
	return 0;
}
