#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll sum[N],n,m,x,l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		sum[i]=sum[i-1]+x;
	}
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<"\n";
	}
	return 0;
}
