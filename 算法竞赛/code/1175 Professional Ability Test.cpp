#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10,inf=1e10+10; 
struct edge{
	ll t2,s,d;
	bool operator < (const edge &a) const
	{
		if(s>a.s) return 1;
		if(s==a.s&&d<a.d) return 1;
		return 0;
	}
};
struct node{
	ll id,dis1,dis2;
	bool operator < (const node &a) const
	{
		if(dis1>a.dis2) return 1;
		if(dis1==a.dis1&&dis2<a.dis2) return 1;
		return 0;
	}
};
vector<edge> e[N];
vector<ll> to[N];
deque<ll> que;
deque<node> dq;
ll n,m,indegree[N],degree[N],k,dis1[N],vis[N],dis2[N],pre[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll t1,t2,s,d;
		cin>>t1>>t2>>s>>d;
		e[t1].push_back((edge){t2,s,d});
		to[t1].push_back(t2);
		indegree[t2]++;
	}
	for(ll i=0;i<=n-1;i++) 
	{
		degree[i]=indegree[i];
		if(!indegree[i]) que.push_back(i);
	}
	ll count=0;
	while(!que.empty())
	{
		ll p=que.front();
		que.pop_front();
		count++;
		for(ll i=0;i<to[p].size();i++)
		{
			ll y=to[p][i];
			indegree[y]--;
			if(indegree[y]==0) que.push_back(y);
		}
	}
	ll flag=1;
	if(count==n) cout<<"Okay.\n";
	else cout<<"Impossible.\n",flag=0;
	cin>>k;
	if(!flag)
	{
		for(ll i=1;i<=k;i++)
		{
			ll x;
			cin>>x;
			if(degree[x]==0) cout<<"You may take test "<<x<<" directly.\n";
			else cout<<"Error.\n";
		}
		return 0;
	}
	for(ll i=0;i<=n-1;i++)	
	{
		dis1[i]=inf;
		if(degree[i]==0)
		{
			dis1[i]=0;
			dq.push_back((node){i,dis1[i],dis2[i]});
		}
	}
	while(!dq.empty())
	{
		node p=dq.front();
		dq.pop_front();
		if(vis[p.id]) continue;
		vis[p.id]=1;
		for(ll i=0;i<e[p.id].size();i++)
		{
			edge y=e[p.id][i];
			if((dis1[y.t2]>dis1[p.id]+y.s)||((dis1[y.t2]==dis1[p.id]+y.s)&&(dis2[y.t2]<dis2[p.id]+y.d)))
			{
				dis1[y.t2]=dis1[p.id]+y.s;
				dis2[y.t2]=dis2[p.id]+y.d;
				pre[y.t2]=p.id;
				dq.push_back((node){y.t2,dis1[y.t2],dis2[y.t2]});
			}
		}
	}
	for(ll i=1;i<=k;i++)
	{
		ll x;
		cin>>x;
		if(degree[x]==0) cout<<"You may take test "<<x<<" directly.\n";
		else
		{
			vector<ll> ans;
			while(1)
			{
		        ans.push_back(x);
		        if(degree[x]==0) break;
				x=pre[x];
			}
			for(ll i=ans.size()-1;i>=0;i--)
			{
				if(i!=0) cout<<ans[i]<<"->";
				else cout<<ans[i]<<"\n";
			}
		}
	}
	return 0;
}
