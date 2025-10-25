#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#pragma GCC optimize(2)
const ll N=1e5+10;
ll n,k,flag,cnt;
ld a[N],sum[N],ss[N],b[N],c[N],t;
void charu(ld x)
{
	if(cnt==0) 
	{
		cnt++;
		b[cnt]=x;
		return;
	}
	ll l=1,r=cnt;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(b[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	if(l>cnt) 
	{
		cnt++;
		b[cnt]=x;
	}
	else 
	{
		cnt++;
		for(ll i=cnt;i>=l+1;i--) b[i]=b[i-1];
		b[l]=x;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>t;
	for(ll i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++) ss[i]=ss[i-1]+a[i]*a[i];
	for(ll i=k;i<=n;i++)
	{
		ld d=(ss[i]-ss[i-k])/k-(sum[i]-sum[i-k])*(sum[i]-sum[i-k])/(k*k);
	//	for(ll j=i-k+1;j<=i;j++) cout<<a[j]<<" ";
		//cout<<"\n";
		//cout<<d<<"\n";
		if(d<t) flag=1;
	}
	if(!flag) 
	{
		cout<<"-1";
		return 0;
	}
	for(ll i=1;i<=n;i++) a[i]=c[i];
	for(ll i=1;i<=n;i++)
	{
		charu(a[i]);
		//for(ll j=1;j<=cnt;j++) cout<<b[j]<<" ";
		//cout<<"\n\n";
		if(cnt<k) continue;
		for(ll j=1;j<=cnt;j++) sum[j]=sum[j-1]+b[j];
		for(ll j=1;j<=cnt;j++) ss[j]=ss[j-1]+b[j]*b[j];
		for(ll j=k;j<=cnt;j++)
		{
			ld d=(ss[j]-ss[j-k])/k-(sum[j]-sum[j-k])*(sum[j]-sum[j-k])/(k*k);
			//for(ll p=j-k+1;p<=j;p++) cout<<b[p]<<" ";
			//cout<<"   "<<d<<"\n";
			if(d<t)
			{
				cout<<cnt;
				return 0;
			}
		}
	}
	return 0;
}
