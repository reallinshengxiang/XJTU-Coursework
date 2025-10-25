#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6,inf=0x3f3f3f3f3f3f3f3f;
struct edge{
	ll from,to,w;
	edge(ll a,ll b,ll c):from(a),to(b),w(c){}
};
vector<edge> e[N];
struct point{
	ll id,ndis;
	point(ll x,ll y):id(x),ndis(y){}
	bool operator<(const point &a) const
	{
		return ndis>a.ndis;
	}
};
ll done[N],dis[N],n=2021;
void dijkstra()
{
	ll s=1;
	for(ll i=1;i<=n;i++)  dis[i]=inf;
	dis[s]=0;
	priority_queue<point> que;
	que.push(point(s,dis[s]));
	while(!que.empty())
	{
		point u=que.top();
		que.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		for(ll i=0;i<e[u.id].size();i++)
		{
			edge y=e[u.id][i];
			if(done[y.to]) continue;
			if(dis[y.to]>y.w+u.ndis)
			{
				dis[y.to]=y.w+u.ndis;
				que.push(point(y.to,dis[y.to]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2021;i++)
	{
		for(ll j=max((ll)1,i-21);j<=min((ll)2024,i+21);j++)
		{
			ll x=__gcd(i,j);
			e[i].push_back(edge(i,j,i*j/x));
		}
	}
	dijkstra();
	cout<<dis[2021];
	return 0;
}
