#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=50010;
ll T,n,t,sum[N],vis[N],prime[N],ph[N];
void get_ph()
{
	ph[1]=1;
	ll cnt=0;
	for(ll i=2;i<=N;i++)
	{
		if(!vis[i])
		{
			vis[i]=i;
			cnt++;
			prime[cnt]=i;
			ph[i]=i-1;
		}
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>N) break;
			vis[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
			{
				ph[i*prime[j]]=ph[i]*prime[j];
				break;
			}
			ph[i*prime[j]]=ph[i]*ph[prime[j]];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	get_ph();
	sum[1]=1;
	for(ll i=2;i<=N;i++) sum[i]=sum[i-1]+ph[i];
	cin>>T;
	while(T--)
	{
		t++;
		cin>>n;
		cout<<t<<" "<<n<<" ";
		cout<<2*sum[n]+1<<"\n";
	}
	return 0;
} 
