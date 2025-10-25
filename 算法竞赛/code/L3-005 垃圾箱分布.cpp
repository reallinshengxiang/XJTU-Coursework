#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=1e3+100,inf=0x3f3f3f3f3f3f3f;
struct edge{
	ll to,w;
};
vector<edge> e[N];
struct point{
	ll id,n_dis;
	bool operator <(const point &x) const
	{
		return n_dis>x.n_dis;
	}
};
point p;
ll dis[N],n,m,k,ds,vis[N];
void dijkstra(ll st)
{
	for(ll i=1;i<=n+m;i++) dis[i]=inf,vis[i]=0;
	dis[st]=0;
	priority_queue<point> que;
	que.push((point){st,dis[0]});
	vis[st]=1;
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		vis[p.id]=1;
		for(ll i=0;i<e[p.id].size();i++)
		{
			ll to=e[p.id][i].to,w=e[p.id][i].w;
			if(vis[to]) continue;
			if(dis[to]>dis[p.n_dis]+w)
			{
				dis[to]=dis[p.n_dis]+w;
				que.push((point){to,dis[to]});
			}
		}
	} 
}
ll to_ll(string s)
{
	ll ans=0;
	for(ll i=0;i<s.size();i++) ans=ans*10+(s[i]-'0');
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k>>ds;
	for(ll i=1;i<=k;i++)
	{
		string s1,s2;
		ll a,b,w;
		cin>>s1>>s2>>w;
		if(s1[0]=='G') 	a=to_ll(s1.substr(1,s1.size()-1))+n;
		else a=to_ll(s1);
		if(s2[0]=='G')  b=to_ll(s2.substr(1,s2.size()-1))+n;
		else b=to_ll(s2);
		e[a].push_back((edge){b,w});
		e[b].push_back((edge){a,w});
	}
	ld ave=0;
	for(ll i=1;i<=m;i++)
	{
		dijkstra(n+i);
		ll flag=0;
		for(ll j=1;j<=n+m;j++) cout<<dis[j]<<" ";
		cout<<"\n";
		ave=0;
		for(ll j=1;j<=n;j++) 
		{
			ave=ave+dis[j];
			if(dis[j]==inf||dis[j]>ds) 
			{
				flag=1;
				break;
			}			
		}
		if(!flag) cout<<fixed<<setprecision(1)<<ave/n<<"\n";
		cout<<"\n";
	}
	return 0;
}
