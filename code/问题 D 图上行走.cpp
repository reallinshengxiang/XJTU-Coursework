#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct Edge{
	ll to,next;
	double w;
};
Edge edge[2*N];
ll cnt,head[N],n,m,d[N],du[N];
queue<ll> q;
double dp[N];
void add_edge(ll from,ll to,double w)
{
	cnt++;
	edge[cnt].to=to;
	edge[cnt].w=w;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		double c;
		cin>>a>>b>>c;
		add_edge(b,a,c);
		du[a]++;
		d[a]++;
	}
	q.push(n);
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		for(ll i=head[x];i;i=edge[i].next)
		{
			ll to=edge[i].to;
			dp[to]=dp[to]+(dp[x]+edge[i].w)/((double)du[to]);
			d[to]--;
			if(!d[to]) q.push(to);
		}
	}
	cout<<fixed<<setprecision(2)<<dp[1];
	return 0;
}
