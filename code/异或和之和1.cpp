#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[5050][5050],ans,a[5050],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		ll j=i; 
		b[i][j]=a[i];
		for(j=i+1;j<=n;j++)	b[i][j]=b[i][j-1]^a[j];
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)	
		{
			cout<<b[i][j]<<" ";
			ans=ans+b[i][j];
		}
		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
