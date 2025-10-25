#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll l,r,n,m,sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>l>>r;
		sum[l+r]++;
	}
	for(ll i=1;i<=N-1;i++) sum[i]=sum[i]+sum[i-1];
	while(m--)
	{
		cin>>l>>r;
		cout<<sum[2*r]-sum[2*l-1]<<"\n";
	} 
	return 0;
}
