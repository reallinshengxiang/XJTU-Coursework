#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[110],a[110],n,heap[110],len=0;
void push(ll x)
{
	ll i;
	len++;
	heap[len]=x;
	i=len;
	while(i>1&&heap[i]>heap[i/2])
	{
		swap(heap[i],heap[i/2]);
		i=i/2;
	}
}
void pop()
{
	heap[1]=heap[len];
	len--;
	ll i=1;
	while(2*i<=len)
	{
		ll son=2*i;
		if(son<len&&heap[son+1]>heap[son]) son++;
		if(heap[son]>heap[i])
		{
			swap(heap[son],heap[i]);
			i=son;
		}
		else break;
	} 
}
void msort(ll *a,ll s,ll t)
{
	if(s==t) return;
	ll mid=(s+t)/2;
	msort(a,s,mid);
	msort(a,mid+1,t);
	ll i=s;
	ll j=mid+1;
	ll k=s;
	while(i<=mid&&j<=t)
	{
		if(a[i]<=a[j])
		{
			r[k]=a[i];
			k++;
			i++;
		}
		else
		{
			r[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		r[k]=a[i];
		k++;
		i++;
	}
	while(j<=t)
	{
		r[k]=a[j];
		k++;
		j++;
	}
	for(ll i=s;i<=t;i++) a[i]=r[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	msort(a,1,n);
	for(ll i=1;i<=n;i++)
	{
		cout<<a[i];
		if(i!=n) cout<<" ";
	}
	cout<<"\n";
	for(ll i=1;i<=n;i++)   push(a[i]);
	for(ll i=1;i<=n;i++)
	{
		cout<<heap[1];
		pop();
		if(i!=n) cout<<" ";
	}
	return 0;
}
