#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100010],m,x,b[10010][10010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>x;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n-1;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			b[i][j]=a[i]^a[j];
		}
	} 
	while(m--)
	{
		ll l,r,flag=1;
		cin>>l>>r;
		for(ll i=l;i<=r-1;i++)
		{
			for(ll j=i+1;j<=r;j++)
			if(b[i][j]==x) 
			{
				cout<<"yes\n";
				flag=0;
				break;
			}			
		}
		if(flag) cout<<"no\n";
	}
	return 0;
 } 
