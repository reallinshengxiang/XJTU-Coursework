#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e8+10,M=6e6+10;
bool vis[N];
ll prime[M],n,q,k,cnt;
void euler(ll n)
{
	for(ll i=2;i<=n;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>n) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	euler(n);
	while(q--)
	{
		cin>>k;
		cout<<prime[k]<<"\n";
	}
	return 0;
}
