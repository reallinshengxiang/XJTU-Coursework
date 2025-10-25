#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll a[N],n,m,ans,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	ans=1;
	sum=0;
	for(ll i=1;i<=n;i++)
	{
		if(sum+a[i]<=m) sum=sum+a[i];
		else
		{
			sum=a[i];
			ans++;
		}
	}	
	cout<<ans;
	return 0;
 } 
