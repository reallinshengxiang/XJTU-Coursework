#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7+10;
ll prime[N],vis[N],cnt;
void euler_sieve()
{
	for(ll i=1;i<N;i++)
	{
		if(!vis[i]) prime[++cnt]=i,cout<<i<<" ";
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>N) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
} 
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	euler_sieve();
	cout<<cnt;
	return 0;
}
