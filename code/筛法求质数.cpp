#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll vis[10100],prime[10100],cnt,n;
void pr()
{
	for(ll i=2;i<n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			prime[cnt]=i;
		}
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
	cin>>n;
	pr();
	for(ll i=1;i<=cnt-1;i++) cout<<prime[i]<<" ";
	if(cnt) cout<<prime[cnt];
	return 0;
}
