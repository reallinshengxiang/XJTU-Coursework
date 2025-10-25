#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
const ll N=1e5+10;
ll a[N],b[N],c[N],d[N],n,ma,mb,suma,sumb;
int main()
{
	cin>>n>>ma;
	for(ll i=ma;i>=1;i--) cin>>a[i];
	cin>>mb;
	for(ll i=mb;i>=1;i--) cin>>b[i];
	for(ll i=1;i<=max(ma,mb);i++) 
	{
		c[i]=max(max(a[i],b[i])+1,(ll)2);
		if(i==1) d[1]=1;
		else d[i]=(d[i-1]*c[i-1])%mod;
	}
	for(ll i=1;i<=ma;i++) suma=(suma+a[i]*d[i])%mod;
	for(ll i=1;i<=mb;i++) sumb=(sumb+b[i]*d[i])%mod;
	cout<<(suma-sumb+mod)%mod;
}
