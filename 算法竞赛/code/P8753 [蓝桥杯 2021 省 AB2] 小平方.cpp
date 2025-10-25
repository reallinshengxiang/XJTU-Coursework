#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n-1;i++)
	{
		if(n%2==0&&(i*i)%n<n/2) ans++;
		else if(n%2==1&&(i*i)%n<=n/2) ans++;
	}
	cout<<ans;
	return 0;
}
