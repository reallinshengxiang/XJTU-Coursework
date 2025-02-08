#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200],n,b[200];
void qsort(ll l,ll r)
{
	ll i,j,mid;
	i=l;
	j=r;
	mid=a[(i+j)/2];
	do{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j) 
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}
void msort(ll l,ll r)
{
        if(l==r) return ;
	ll mid=(l+r)/2;
	msort(l,mid);
	msort(mid+1,r);
	ll i=l,k=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) 
		{
			b[k]=a[i];
			k++;
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
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
	for(ll i=1;i<=n;i++) a[i]=rand()%100+1;
	qsort(1,n);
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	for(ll i=1;i<=n;i++) a[i]=rand()%100+1;
	msort(1,n);
        for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<"\n";
}
