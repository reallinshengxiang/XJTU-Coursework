#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[50],ans,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=30;i++) scanf("%lld,",&a[i]);
	for(ll i=1;i<=30;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=29;i++)
	{
		for(ll j=i+1;j<=30;j++)
		{
			cnt++;
			if(a[i]*a[j]>=2022) ans++,cout<<ans<<"  "<<a[i]<<" "<<a[j]<<" "<<a[i]*a[j]<<"\n";
		}
	}
	cout<<ans<<" "<<cnt;
	return 0;
}
