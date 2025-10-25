#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n/2;i++) a[i]=n*2-i*2,cout<<a[i]<<"\n";
	if(n%2) cout<<a[n/2]-2<<"\n";
	for(ll i=n/2;i>=1;i--) cout<<a[i]<<"\n";
	return 0;
}
