#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,l,r,mid,len=1,a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	b[1]=a[1];
	for(ll i=2;i<=n;i++)
	{
		l=1,r=len;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(b[mid]<a[i]) l=mid+1;
			else r=mid-1;
		}
		b[l]=a[i];
		if(l>len) len++;
	}
	cout<<len;
	return 0;
}


