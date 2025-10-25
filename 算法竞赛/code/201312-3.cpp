#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll ans,minn,h[N],n,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>h[i];
	for(ll i=1;i<=n;i++)
	{
		minn=h[i]; 
		for(ll j=i;j<=n;j++)
		{
			minn=min(minn,h[j]);
			s=(j-i+1)*minn;
			ans=max(ans,s);
		}
	}
	cout<<ans;
	return 0;
}
