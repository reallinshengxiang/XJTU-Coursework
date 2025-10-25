#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct edge{
	ll to,w;
};
vector<edge> e[N];
deque<ll> dq;
ll n,m,in[N],degree[N],p;
double dp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
    	ll u,v,w;
    	cin>>u>>v>>w;
    	e[v].push_back(edge{u,w});
    	in[u]++;
    	degree[u]++;
	}
	dq.push_back(n);
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<e[p].size();i++)
		{
			ll to=e[p][i].to,w=e[p][i].w;
			dp[to]=dp[to]+(dp[p]+w)*1.0/degree[to];
			//cout<<to<<"  "<<fixed<<setprecision(2)<<dp[to]<<"  "<<in[to]<<"\n";
			in[to]--;
			if(in[to]==0) dq.push_back(to);
		}
	}
	cout<<fixed<<setprecision(2)<<dp[1];
	return 0;
}
