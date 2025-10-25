#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll ans[N],T,cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=N-1;i++)
	{
		for(ll j=i;j<=N-1;j=j+i) cnt[j]++;
	}
	for(ll i=1;i<=N-1;i++) ans[i]=ans[i-1]+cnt[i];
	cin>>T;	
	while(T--)
	{
		ll a,b;
		cin>>a>>b;
		cout<<ans[b]-ans[a-1]<<"\n";
	}
	return 0;
}
