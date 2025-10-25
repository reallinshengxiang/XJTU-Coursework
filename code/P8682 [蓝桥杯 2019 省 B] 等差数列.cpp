#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],b,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b=a[2]-a[1];
	if(b==0) 
	{
		cout<<n;
		return 0;
	}
	for(ll i=1;i<=n-1;i++)	b=min(a[i+1]-a[i],b);
	cout<<(a[n]-a[1])/b+1;
	return 0;
} 
