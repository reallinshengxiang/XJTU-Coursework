#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],l,r,s[100010],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	}
	while(m--)
	{
		cin>>l>>r;
		cout<<s[r]-s[l-1]<<"\n";
	}
	return 0;
}
