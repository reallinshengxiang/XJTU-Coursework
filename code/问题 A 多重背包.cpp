#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,V,dp[N],q[N],num[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>V>>n;
	for(ll i=1;i<=n;i++)
	{
		ll m,v,w;
		cin>>m>>v>>w;
		if(m>V/v) m=V/v;
		for(ll b=0;b<=v-1;b++)
		{
			ll head=1,tail=0;
			for(ll y=0;y<=(V-b)/v;y++)
			{
				ll tmp=dp[b+y*v]-y*w;
				while(head<=tail&&q[tail]<=tmp) tail--;
				tail++;
				q[tail]=tmp;
				num[tail]=y;
				while(head<=tail&&y-num[head]>m) head++;
				dp[b+y*v]=max(dp[b+y*v],q[head]+y*w);
			}
		}
	}
	cout<<dp[V];
	return 0;
}
