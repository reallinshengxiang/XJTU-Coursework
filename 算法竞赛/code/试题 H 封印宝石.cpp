#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#pragma GCC optimize(2)
const ll N=1e5+10;
ll n,k,a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i],b[i]=-1;
	for(ll i=1;i<=n-1;i++)
	{
		k=k-1;
		if(k<0) break;
		b[i]=a[i+1];
	}
	for(ll i=1;i<=n;i++) cout<<b[i]<<" ";
	return 0;
}
