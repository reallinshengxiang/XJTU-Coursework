#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20010],b[20010],n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i];
		b[i]=(b[i-1]+a[i])%10; 
	}
	for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
	for(ll i=n+1;i<=n+m;i++)  
	{
	    cout<<(b[i-1]-b[i-n-1]+10)%10<<" ";
	    b[i]=((b[i-1]-b[i-n-1]+10)+b[i-1])%10;
	}
	return 0;
}
