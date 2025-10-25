#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct point{
	ll pos,dis;
};
deque<point> dq;
point p;
ll pp,n,k,vis[N],dis[N],ans,maxx,x;
vector<ll> e[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			cin>>x;
			e[i].push_back(x);
			vis[x]=1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i]) 
		{
			p.pos=i;
			p.dis=0;
			break;
		}
	}
	dq.push_back(p);
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<e[p.pos].size();i++)
		{
			pp=e[p.pos][i];
			if(dis[pp]) continue;
			dis[pp]=p.dis+1;
			dq.push_back((point){pp,dis[pp]});
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(dis[i]>=maxx)
		{
			maxx=dis[i];
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
