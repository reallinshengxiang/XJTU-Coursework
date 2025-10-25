#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=3e4;
ll n,k,x,y,sum[N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	while(k--)
	{
		cin>>x>>y;
		if(x>y) swap(x,y);
		sum[x]++;
		sum[y+1]--; 
	} 
	for(ll i=1;i<=n;i++) a[i]=a[i-1]+sum[i];
	sort(a+1,a+n+1);
	cout<<a[n/2+1];
	return 0;
}
