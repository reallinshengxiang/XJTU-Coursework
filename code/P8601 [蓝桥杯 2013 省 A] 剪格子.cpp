#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=11;
ll dx[5]={1,-1,0,0};
ll dy[5]={0,0,1,-1};
ll sum,a[N][N],vis[N][N],n,m,ans;
void search(ll x,ll y,ll cnt,ll now)
{
	if(now==sum)
	{
		ans=cnt;
		return;
	}
	if(now>sum) return;
	for(ll i=0;i<=3;i++)
	{
		ll px=x+dx[i];
		ll py=y+dy[i];
		if(!(px>=1&&px<=n&&py>=1&&py<=m&&!vis[px][py])) continue;
		vis[px][py]=1;
		search(px,py,cnt+1,now+a[px][py]);
		if(ans) return;
		vis[px][py]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j],sum=sum+a[i][j];
	}
	if(sum%2) 
	{
		cout<<"0";
		return 0;
	}
	sum=sum/2;
	search(1,1,1,a[1][1]);
	cout<<ans;
	return 0;
}
