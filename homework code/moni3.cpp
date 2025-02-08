#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20],b[20],n;
void msort(ll l,ll r)
{
	if(l==r) return;
	ll mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	ll i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=r)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(ll i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	msort(1,n);
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
