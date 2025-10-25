#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll vis[N],prime[N],cnt;
void euler_seive(ll n)
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
	euler_seive(2020); 
	cout<<2020-1-cnt;
	return 0;
} 
// 1713
