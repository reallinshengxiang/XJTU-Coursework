#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n,a[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==i) continue;
		for(ll j=i+1;j<=n;j++)
		{
			if(a[j]==i) 
			{
				swap(a[i],a[j]);
				ans++;
				break;
			}		
		}
	}
	cout<<ans;
	return 0;
}
