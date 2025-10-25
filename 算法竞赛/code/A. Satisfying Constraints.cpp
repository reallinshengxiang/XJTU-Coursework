#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
struct con{
	ll a,x;
};
con c[N];
ll ans,T,n,l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>c[i].a>>c[i].x;
		l=0;
		r=1e9+10;
		for(ll i=1;i<=n;i++)
		{
			if(c[i].a==1) l=max(l,c[i].x);
			if(c[i].a==2) r=min(r,c[i].x);
		}
		ans=r-l+1;
		map<ll,ll> mp;
		for(ll i=1;i<=n;i++)
		{
			if(c[i].a==3)
			{
				if(c[i].x>=l&&c[i].x<=r&&!mp[c[i].x])
				{
					mp[c[i].x]=1;
					ans--;
				}
			}
		}
		ans=max((ll)0,ans);
		cout<<ans<<"\n";
	}
	return 0;
}
