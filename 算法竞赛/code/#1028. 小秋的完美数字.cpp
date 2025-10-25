#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l=1,r=1000000000,xx;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		cout<<mid<<"\n";
		fflush(stdout);
		cin>>xx;
		if(!xx) return 0;
		else if(xx==-1) l=mid+1;
		else r=mid-1;
	}	
	return 0;
}
