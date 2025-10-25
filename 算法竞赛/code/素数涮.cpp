#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll cnt,vis[N],p[N],n; 
void euler_sieve(ll n)
{
	for(ll i=2;i<=n;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*p[j]>n) break;
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	euler_sieve(n);
	cout<<cnt<<"\n"; 
	for(ll i=1;i<=cnt;i++) cout<<p[i]<<"\n";
	return 0;
}
