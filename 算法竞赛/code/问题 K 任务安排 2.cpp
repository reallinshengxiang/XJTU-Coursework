#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n,s,f[N],t[N],c[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	for(ll i=1;i<=n;i++)
	{
		cin>>t[i]>>c[i];
		t[i]=t[i-1]+t[i];
		c[i]=c[i-1]+c[i];
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<=i-1;j++) f[i]=min(f[i],f[j]+(c[i]-c[j])*t[i]+(c[n]-c[j])*s);
	}
	cout<<f[n]; 
	return 0;
}
