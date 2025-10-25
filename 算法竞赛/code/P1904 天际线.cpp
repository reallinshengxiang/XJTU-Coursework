#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll l,x,r,h[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>l>>x>>r)
	{
		for(ll i=l;i<=r-1;i++) h[i]=max(h[i],x);
	}
	x=0;
	for(ll i=0;i<=1e4;i++)
	{
		if(x!=h[i])
		{
			x=h[i];
			cout<<i<<" "<<x<<" ";
		}
	}
	return 0;
}
