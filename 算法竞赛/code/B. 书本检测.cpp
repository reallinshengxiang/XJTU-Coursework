#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int query(long long l,long long r)
{
	printf("? %lld %lld\n",l,r);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main()
{
	cin>>n;
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(query(l,mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<l<<"\n";
	return 0;
}
