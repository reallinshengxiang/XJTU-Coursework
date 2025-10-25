#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10,inf=1e10+10;
struct edge{
	ll y,val;
};
vector<edge> e[N];
ll nv,ne,k,dis[N],a[N],dq[N*2],vis[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>nv>>ne;
	for(ll i=1;i<=ne;i++)
	{
		ll x,y,val;
		cin>>x>>y>>val;
		e[x].push_back((edge){y,val});
		e[y].push_back((edge){x,val});
	}
	cin>>k;
	while(k--)
	{
		for(ll i=1;i<=nv;i++) dis[i]=inf,vis[i]=0;
		for(ll i=1;i<=nv;i++) cin>>a[i];
		ll st=1,ed=1,flag=1;
		dq[st]=a[1];
		dis[a[1]]=0;
		vis[a[1]]=1;
		for(ll i=1;i<=nv;i++)
		{
			ll minn=inf,pos=1;
			for(ll j=st;j<=ed;j++) minn=min(minn,dis[dq[j]]);
			if(dis[a[i]]!=minn)
			{
				flag=0;
				break;
			}
			for(ll j=st;j<=ed;j++)
			{
				if(dq[j]==a[i])
				{
					pos=j;
					break;
				}
			}
			swap(dq[pos],dq[st]);
			st++;
			for(ll j=0;j<e[a[i]].size();j++)
			{
				ll y=e[a[i]][j].y;
				ll w=e[a[i]][j].val;
				if(dis[y]>dis[a[i]]+w)
				{
					dis[y]=dis[a[i]]+w;
					if(!vis[y])
					{
						vis[y]=1;
						ed++;
						dq[ed]=y;
					}
				}
			}
		}
		if(!flag) cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
