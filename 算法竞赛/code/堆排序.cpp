#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110],n;
void heap(ll nn,ll ii)
{
	ll x,i=ii,j;
	x=a[ii];
	j=2*i;
	while(j<=nn)
	{
		if(j<nn&&a[j]<a[j+1]) j++;
		if(x<a[j])
		{
			a[i]=a[j];
			i=j;
			j=2*i;
		}
		else break;
	}
	a[i]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) a[i]=(rand()%1000)+100;
	for(ll i=1;i<=n;i++) cout<<a[i]<<"  ";
	cout<<"\n";
	for(ll i=n/2;i>=1;i--) heap(n,i);
	for(ll i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		heap(i-1,1);
	}
	for(ll i=1;i<=n;i++) cout<<a[i]<<"  ";
	cout<<"\n";
	return 0;
 } 
