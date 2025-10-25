#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m,T,a[N],b[N],st,ed,stt,edd,ans,f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=m;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		for(ll i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
		for(ll i=1;i<=m;i++) sumb[i]=sumb[i-1]+b[i];
		
		cout<<ans<<"\n";
	}
	return 0;
}
