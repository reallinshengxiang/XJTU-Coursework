#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100],b[100],n;
void print();
void qpx(ll k)
{
	if(k==n+1)
	{
		print();
		return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			a[k]=i;
			qpx(k+1);
			b[i]=0;
		}
	}
}
void print()
{
	for(ll i=1;i<=n;i++) cout<<a[i];
	cout<<"\n";
}
int main()
{
	cin>>n;
	qpx(1);
	return 0;
}
