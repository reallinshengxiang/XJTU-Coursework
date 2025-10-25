#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
ll n,m,b[N][N],a[N*N],tim[N][N],flag[N][100010],f,x,step,bb,tt,now[N],alast[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=m*n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>b[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		now[i]=1;
		for(ll j=1;j<=m;j++) cin>>tim[i][j];
	}
	for(ll i=1;i<=n*m;i++)
	{
		x=a[i];
		step=now[x];
		bb=b[x][step];
		tt=tim[x][step];
		ll t=alast[x];
		while(1)
		{
			f=1;
			for(ll j=t;j<=t+tt-1;j++)
			{
				if(flag[bb][j])
				{
					f=0;
					break;
				}
			}
			if(f)
			{
				alast[x]=t+tt;
				now[x]++;
				if(t+tt>ans) ans=t+tt;
				for(ll j=t;j<=t+tt-1;j++) flag[bb][j]=1;
				break;
			}
			t++;
		}
	}
	cout<<ans;
	return 0;
}
