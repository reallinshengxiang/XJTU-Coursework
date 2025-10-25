#include<iostream>
using namespace std;
#define ll long long
void BubbleSort(ll *a,ll n)
{
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
void SelectionSort(ll *a,ll n)
{
	ll maxx;
	for(ll i=1;i<=n;i++)
	{
		maxx=i;
		for(ll j=i+1;j<=n;j++)
		{
			if(a[j]>a[maxx]) maxx=j;
		}
		swap(a[i],a[maxx]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n=10,a[22];
	for(ll i=1;i<=n;i++)  cin>>a[i];
	BubbleSort(a,n);
	for(ll i=1;i<=n;i++)
	{
		cout<<a[i];
		if(i!=n) cout<<" ";
		else cout<<"\n"; 
	}
	SelectionSort(a,10);
	for(ll i=1;i<=n;i++)
	{
		cout<<a[i];
		if(i!=n) cout<<" ";
	}
	return 0;
}
