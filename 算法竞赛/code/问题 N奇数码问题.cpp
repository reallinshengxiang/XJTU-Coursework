#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1,ans2,n,a[250010],b[250010],rr[2500010],x;
void msort1(ll l,ll r)
{
	if(l==r) return;
	ll mid=(l+r)/2;
	msort1(l,mid);
	msort1(mid+1,r);
	ll i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r) 
	{
		if(a[i]<=a[j]) 
		{
			rr[k]=a[i];
			i++;
			k++;
		} 
		else 
		{
			rr[k]=a[j];
			k++;
			j++;
			ans1=ans1+mid-i+1;
		}
	}
	while(i<=mid) 
	{
		rr[k]=a[i];
		k++;
		i++;
	}
	while(j<=r) 
	{
		rr[k]=a[j];
		k++;
		j++;
	}
	for(ll i=l; i<=r; i++) a[i]=rr[i];
}
void msort2(ll l,ll r)
{
	if(l==r) return;
	ll mid=(l+r)/2;
	msort2(l,mid);
	msort2(mid+1,r);
	ll i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r) 
	{
		if(b[i]<=b[j]) 
		{
			rr[k]=b[i];
			i++;
			k++;
		} 
		else 
		{
			rr[k]=b[j];
			k++;
			j++;
			ans2=ans2+mid-i+1;
		}
	}
	while(i<=mid) 
	{
		rr[k]=b[i];
		k++;
		i++;
	}
	while(j<=r) 
	{
		rr[k]=b[j];
		k++;
		j++;
	}
	for(ll i=l; i<=r; i++) b[i]=rr[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n) 
	{
		if(n==1) 
		{
			cin>>a[0]>>b[0];
			cout<<"TAK\n";
		}
		else 
		{
			ans1=ans2=0;
			for(ll i=1; i<=n*n; i++) 
			{
				cin>>a[i];
				if(a[i]==0) x=i;
			}
			for(ll i=x; i<=n*n; i++) a[i]=a[i+1];
			for(ll i=1; i<=n*n; i++)
			{
				cin>>b[i];
				if(b[i]==0) x=i;
			}
			for(ll i=x; i<=n*n; i++) b[i]=b[i+1];
			msort1(1,n*n-1);
			memset(rr,0,sizeof(rr));
			msort2(1,n*n-1);
			if((ans1%2)==(ans2%2)) cout<<"TAK\n";
			else cout<<"NIE\n";
		}
	}
	return 0;
}
