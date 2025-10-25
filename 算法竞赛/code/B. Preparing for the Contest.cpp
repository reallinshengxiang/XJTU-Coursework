#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
ll T,a[N],n,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++) a[i]=n+1-i;
		for(ll i=1;i<=k;i++) swap(a[i],a[n-i+1]);
		for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
