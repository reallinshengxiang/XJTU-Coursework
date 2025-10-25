#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550,M=1e5+10;
struct edge{
	ll to,w;
};
vector<edge> e[M];
struct node{
	ll id,dis;
	bool operator<(const node &u) const{return dis>u.dis;}
};
ll n,m;
bool done[N];
void prim()
{
	ll s=1;
	priority_queue<node> q;
	q.push((node){s,0});
	ll ans=0,cnt=0;
	while(!q.empty())
	{
		node u=q.top();
		q.pop();
		if(done[u.id]) continue;
		done[u.id]=1;
		ans=ans+u.dis;
		cnt++;
		for(ll i=0;i<e[u.id].size();i++)
		{
			edge y=e[u.id][i];
			if(done[y.to]) continue;
			q.push((node){y.to,y.w});
		}
	}
	if(cnt==n) cout<<ans;
	else cout<<"impossible";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,w;
		cin>>a>>b>>w;
		e[a].push_back((edge){b,w});
		e[b].push_back((edge){a,w});
	}
	prim();
	return 0;
}
