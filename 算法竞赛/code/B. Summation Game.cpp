#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll T,ans,a[N],sum[N],n,k,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>x;
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		ans=sum[n-x]-(sum[n]-sum[n-x]);
		for(ll i=n-x;i>=max(n-k-x,(ll)0);i--)	ans=max(sum[i]-(sum[i+x]-sum[i]),ans);
		if(n-k<=x) ans=max(ans,-sum[n-k]);
		cout<<ans<<"\n";
	}
	return 0; 
}
