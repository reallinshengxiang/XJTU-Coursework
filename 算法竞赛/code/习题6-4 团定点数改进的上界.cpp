#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll ans,f[N],ansx[N],e[N][N],a[N],mindegree[N],n,m,cnt,degree[N];
void bbMaxClique(ll step)
{
	if(step>n) 
	{
		if(ans<cnt)
		{
			ans=cnt;
			for(ll i=1;i<=cnt;i++) ansx[i]=a[i];
		}
		return;
	}
	ll flag=1;
	for(ll i=1;i<=step-1;i++)
	{
		if(f[i]&&!e[step][i])
		{
			flag=0;
			break;
		}
	}
	if(flag)
	{
		cnt++;
		if(cnt+mindegree[step]+1>=ans&&cnt+n-step>=ans)
		{
			a[cnt]=step;
		    f[step]=1;
		    bbMaxClique(step+1);
		    cnt--;
		    f[step]=0;
		}		
	} 
	if(cnt+mindegree[step]+1>=ans&&cnt+n-step>=ans)
	{
		f[step]=0;
		bbMaxClique(step+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		if(!e[x][y])  degree[x]++,degree[y]++;
		e[x][y]=e[y][x]=1;
	}
	for(ll i=1;i<=n;i++)
	{
		mindegree[i]=n;
		for(ll j=1;j<=n;j++)
		{
			if(e[i][j]) mindegree[i]=min(mindegree[i],degree[j]);
		}
	}
	bbMaxClique(1);
	cout<<ans<<"\n";
	for(ll i=1;i<=ans;i++) cout<<ansx[i]<<" ";
	return 0;
} 


