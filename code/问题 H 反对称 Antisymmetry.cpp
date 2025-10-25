#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const ll N=5e5+10,pp=131; 
ll n,ans;
char s[N],t[N];
ull p[N],f[N],g[N]; 
void bin_search(ll x)
{
	ll l=1,r=min(x,n-x);
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(f[x]-f[x-mid]*p[mid]==g[x+1]-g[x+1+mid]*p[mid]) l=mid+1;
		else r=mid-1;
	}
	ans=ans+l-1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>(s+1);
	p[0]=1;
	for(ll i=1;i<=n;i++) p[i]=p[i-1]*pp;
	for(ll i=1;i<=n;i++)
	{
		if(s[i]=='1') t[i]='0';
		else t[i]='1';
	}
	for(ll i=1;i<=n;i++) f[i]=f[i-1]*pp+s[i];
	for(ll i=n;i>=1;i--) g[i]=g[i+1]*pp+t[i];
	for(ll i=1;i<=n-1;i++) bin_search(i);
	cout<<ans; 
	return 0;
}
