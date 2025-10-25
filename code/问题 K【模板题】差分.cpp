#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],b[100010],l,r,c,s[100010],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=a[i]-a[i-1];
	}
	while(m--)
	{
		cin>>l>>r>>c;
		s[l]=s[l]+c;
		s[r+1]=s[r+1]-c;
	}
	for(ll i=1;i<=n;i++)
	{
		b[i]=b[i-1]+s[i];
		cout<<b[i]<<" ";
	}
	return 0;
}
