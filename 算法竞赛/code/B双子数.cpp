#include<bits/stdc++.h>
using namespace std;
#define ll __int128
const ll N=5e6+10;
ll prime[N],vis[N],cnt,ans,x;
void euler_sieve()
{
	for(ll i=2;i<N;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>=N) break;
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
	cout<<"\n";
	for(ll i=1;i<=cnt-1;i++)
	{
		for(ll j=i+1;j<=cnt;j++)
		{
			if(23333333333333<prime[i]*prime[i]*prime[j]*prime[j]) break;
			if(2333<prime[i]*prime[i]*prime[j]*prime[j]) ans++;
		}
	}
	cout<<(long long)ans;
	return 0;
}
//947293 
