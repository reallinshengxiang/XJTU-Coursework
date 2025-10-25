#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],b[N],len,maxx,dp[N],pos,n,k,c[N],f[N];
map<ll,ll> mp;
ll search(ll x)
{
	ll l=1,r=len,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(c[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
ll search2(ll x)
{
	ll l=1,r=len,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(c[mid]>x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i],b[n+1-i]=a[i];
	for(ll i=1;i<=n;i++)
	{
		if(len==0)
		{
			len++;
			c[len]=a[i];
			dp[i]=len;
		}
		else if(a[i]>=c[len])
		{
			len++;
			c[len]=a[i];
			dp[i]=len;
		}
		else
		{
			pos=search(a[i]);
			c[pos]=a[i];
			dp[i]=pos;
		}
	}
	len=0;
	memset(c,0,sizeof(c));
	for(ll i=1;i<=n;i++)
	{
		if(len==0)
		{
			len++;
			c[len]=b[i];
			f[n-i+1]=len;
		}
		else if(b[i]<=c[len])
		{
			len++;
			c[len]=b[i];
			f[n-i+1]=len;
		}
		else 
		{
			pos=search2(b[i]);
			c[pos]=b[i];
			f[n-i+1]=pos;
		}
	}
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=n;i++) cout<<dp[i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=n;i++) cout<<f[n+1-i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(i+k>=n) maxx=max(maxx,dp[i]+n-i);
		else if(a[i+k+1]>=a[i]) maxx=max(maxx,dp[i]+k+f[i+k+1]);
		else maxx=max(maxx,dp[i]+k);
		//cout<<i<<"  "<<dp[i]<<"  "<<f[k+i+1]<<"  "<<maxx<<"\n";
	}
	for(ll i=1;i<=n;i++)
	{
		if(i-k<=1) maxx=max(maxx,f[i]+i-1);
		else if(a[i-k-1]<=a[i]) maxx=max(maxx,dp[i-k-1]+k+f[i]);
		else maxx=max(maxx,f[i]+k);
	}
	cout<<maxx;
	return 0;
}
/*
100 49
41 80 49 99 86 96 24 12 100 92 62 26 33 62 43 99 98 55 3 25 94 68 54 37 23 83 40 85 60 28 56 11 20 55 65 24 92 50 42 88 91 67 82 57 80 15 13 54 51 9 12 7 71 100 51 91 84 11 78 99 96 94 81 69 25 77 24 44 21 84 26 52 40 39 56 84 50 8 16 18 90 32 54 48 26 53 70 78 20 56 57 11 38 38 82 91 72 71 45 78
*/
