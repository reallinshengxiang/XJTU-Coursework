#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll ans,n,m,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n+m+1;i++) cin>>a[i],ans=ans+a[i];
	sort(a+1,a+n+m+2);
	if(m==0)  cout<<ans;
	else
	{
		ans=a[n+m+1]-a[1];
		for(ll i=2;i<=n+m;i++) ans=ans+abs(a[i]);
		cout<<ans;
	}
	return 0; 
}
