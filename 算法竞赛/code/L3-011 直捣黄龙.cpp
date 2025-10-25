#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220,inf=0x3f3f3f3f3f3f;
struct edge{
	ll to,w;
};
vector<edge> e[N];
vector<ll> ans;
struct node{
	ll id,n_dis;
	bool operator < (const node &nn) const
	{
		if(n_dis>nn.n_dis) return 1;
		return 0;
	}
};
map<string,ll> mp;
map<ll,string> pm;
string s1,s2,s;
ll n,k,x,cnt,peo[N],dis[N],vis[N],sum[N],killpeo[N],lib[N],pre[N];
void dijkstra()
{
	for(ll i=0;i<N;i++) dis[i]=inf;
	dis[1]=0;
	priority_queue<node> q;
	q.push((node){1,0});
	while(!q.empty())
	{
		node p=q.top();
		q.pop();
		if(vis[p.id]) continue;
		vis[p.id]=1;
		sum[1]=1;
		for(ll i=0;i<e[p.id].size();i++)
		{
			ll to=e[p.id][i].to,w=e[p.id][i].w;
			if(dis[to]>dis[p.id]+w)
			{
				dis[to]=dis[p.id]+w;
				killpeo[to]=killpeo[p.id]+peo[to];
				sum[to]=sum[p.id];
				lib[to]=lib[p.id]+1;
				pre[to]=p.id;
				q.push((node){to,dis[to]});
			}
			else if(dis[to]==dis[p.id]+w)
			{
				sum[to]=sum[to]+sum[p.id];
				if(lib[to]<lib[p.id]+1)
				{
					lib[to]=lib[p.id]+1;
					killpeo[to]=killpeo[p.id]+peo[to];
					pre[to]=p.id;
					q.push((node){to,dis[to]});
				}
				else if(lib[to]==lib[p.id]+1&&killpeo[to]<killpeo[p.id]+peo[to])
				{
					killpeo[to]=killpeo[p.id]+peo[to];
					pre[to]=p.id;
					q.push((node){to,dis[to]});
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cin>>s1>>s2;
	mp[s1]=1;
	pm[1]=s1;
	mp[s2]=2;
	pm[2]=s2;
	cnt=2;
	for(ll i=1;i<=n-1;i++)
	{
		cin>>s>>x;
		if(!mp[s]) 
		{
			cnt++;
			mp[s]=cnt;
			pm[cnt]=s;
		}
		peo[mp[s]]=x;
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>s1>>s2>>x;
		ll x1=mp[s1];
		ll x2=mp[s2];
		e[x1].push_back((edge){x2,x});
		e[x2].push_back((edge){x1,x});
	}
	dijkstra();
	ll pos=2;
	while(pos)
	{
		ans.push_back(pos);
		pos=pre[pos]; 
	}
	for(ll i=ans.size()-1;i>=0;i--)
	{
		cout<<pm[ans[i]];
		if(i!=0) cout<<"->";
	}
	cout<<"\n"<<sum[2]<<" "<<dis[2]<<" "<<killpeo[2];
	return 0;
} 
