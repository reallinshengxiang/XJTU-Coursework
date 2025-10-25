#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010],r[1000010],n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	msort(1,n); 
	cout<<ans;
	return 0;
 } 
