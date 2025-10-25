#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll g[N],n,a,b,c,m,lx[N],rx[N],ly[N],ry[N],lz[N],rz[N],d[N],s[N];
ll num(ll x,ll y,ll k)
{
	if(x>a||y>b||k>c) return 0;
	return ((x-1)*b+(y-1))*c+(k-1)+1;
}
ll check(ll x)
{
	memset(g,0,sizeof(g));
	for(ll i=1;i<=x;i++)
	{
		g[num(lx[i],ly[i],lz[i])]+=d[i];
        g[num(rx[i]+1,ry[i]+1,lz[i])]+=d[i];
		g[num(rx[i]+1,ly[i],rz[i]+1)]+=d[i];
		g[num(lx[i],ry[i]+1,rz[i]+1)]+=d[i];
		g[num(rx[i]+1,ry[i]+1,rz[i]+1)]-=d[i];
		g[num(lx[i],ry[i]+1,lz[i])]-=d[i];
		g[num(lx[i],ly[i],rz[i]+1)]-=d[i];	
		g[num(rx[i]+1,ly[i],lz[i])]-=d[i];
	}
	for(ll i=1;i<=a;i++)
	{
		for(ll j=1;j<=b;j++)
		{
			for(ll k=2;k<=c;k++) g[num(i,j,k)]=g[num(i,j,k)]+g[num(i,j,k-1)];
		}
	}
	for(ll i=1;i<=a;i++)
	{
		for(ll k=1;k<=c;k++)
		{
			for(ll j=2;j<=b;j++) g[num(i,j,k)]=g[num(i,j,k)]+g[num(i,j-1,k)];
		}
	}
	for(ll k=1;k<=c;k++)
	{
		for(ll j=1;j<=b;j++)
		{
			for(ll i=2;i<=a;i++) g[num(i,j,k)]=g[num(i,j,k)]+g[num(i-1,j,k)];
		}
	}
	for(ll i=1;i<=n;i++) 
	{
		if(g[i]>s[i]) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>m;
	n=a*b*c;
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=m;i++) cin>>lx[i]>>rx[i]>>ly[i]>>ry[i]>>lz[i]>>rz[i]>>d[i];
	ll l=1,r=m,mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
