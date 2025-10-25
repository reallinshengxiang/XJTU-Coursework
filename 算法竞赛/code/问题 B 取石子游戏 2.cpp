#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,x,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x;
	ans=x;
	for(ll i=2;i<=n;i++)
	{
		cin>>x;
		ans=ans^x;
	}
	if(ans==0) cout<<"lose";
	else cout<<"win";
	return 0;
 } 
