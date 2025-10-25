#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=2e5+10,M=1e3+10;
ll n,m,k,x,ans,st[M],ed[M],a[N],to[N],pos[N],step[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ll block=sqrt(n);
	ll t=n/block;
	if(n%block) t++;
	for(rll i=1;i<=t;i++)
	{
		st[i]=(i-1)*block+1;
		ed[i]=i*block; 
	}
	ed[t]=n;
	for(rll i=1;i<=n;i++) pos[i]=(i-1)/block+1;
	for(rll i=1;i<=n;i++) cin>>a[i];
	for(rll i=n;i>=1;i--)
	{
		to[i]=i+a[i];
		if(to[i]>ed[pos[i]]) step[i]=1;
		else 
		{
			step[i]=step[to[i]]+1;
			to[i]=to[to[i]];
		}
	}
	cin>>m;
	while(m--)
	{
		ll opt;
		cin>>opt;
		if(opt==1)
		{
			cin>>x;
			x++;
			ans=0;
			while(x<=n) 
			{
				ans=ans+step[x];
				x=to[x];
			}
			cout<<ans<<"\n";
		}
		else if(opt==2)
		{
			cin>>x>>k;
			x++;
			a[x]=k;
			for(rll i=ed[pos[x]];i>=st[pos[x]];i--)
			{
				to[i]=i+a[i];
		        if(to[i]>ed[pos[i]]) step[i]=1;
		        else 
		        {
		        	step[i]=step[to[i]]+1;
			        to[i]=to[to[i]];
		        }	
			}
		}
	}
	return 0;
}
