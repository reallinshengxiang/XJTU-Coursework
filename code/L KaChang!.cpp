#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,x,T,n,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>T>>t;
	for(ll i=2;i<=n;i++) 
	{
		cin>>x;
		t=max(t,x);
	}
	k=t/T;
	if(k*T<t) k++;
	cout<<max((ll)2,k);
	return 0;
}
