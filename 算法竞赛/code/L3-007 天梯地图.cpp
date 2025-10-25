#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10,inf=0x3f3f3f3f3f3f3f;
struct edge{
	ll to,length,time;
};
vector<edge> e[N];
vector<ll> e1,e2;
ll st,ed,n,m,dis[N],vis[N],dispre[N],disnum[N],timpre[N],timnum[N],tim[N];
struct point{
	ll id,n_dis;
	bool operator < (const point &p) const
	{
		return n_dis>p.n_dis;
	}
};
point p;
void dijkstra()
{
	for(ll i=1;i<=n;i++) dis[i]=inf,vis[i]=0,dispre[i]=-1;
	dis[st]=0;
	priority_queue<point> que;
	que.push((point){st,dis[st]});
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		if(vis[p.id]) continue;
		vis[p.id]=1;
		for(ll i=0;i<e[p.id].size();i++)
		{
			ll to=e[p.id][i].to,w=e[p.id][i].length;
			if(vis[to]) continue;
			if(dis[to]>p.n_dis+w)
			{
				dis[to]=p.n_dis+w;
				que.push((point){to,dis[to]});
				disnum[to]=disnum[p.id]+1;
				dispre[to]=p.id;
			}
			else if(dis[to]==p.n_dis+w)
			{
				if(disnum[p.id]+1<disnum[to])
				{
					disnum[to]=disnum[p.id]+1;
				    dispre[to]=p.id;
				}
			}
		}
	}
}
void get_dispath(ll x)
{
	while(dispre[x]!=-1) 
	{
		e1.push_back(x);
		x=dispre[x];
	}
}
void dijkstra2()
{
	for(ll i=1;i<=n;i++) tim[i]=inf,vis[i]=0,timpre[i]=-1;
	tim[st]=0;
	priority_queue<point> que;
	que.push((point){st,tim[st]});
	while(!que.empty())
	{
		p=que.top();
		que.pop();
		if(vis[p.id]) continue;
		vis[p.id]=1;
		for(ll i=0;i<e[p.id].size();i++)
		{
			ll to=e[p.id][i].to,w=e[p.id][i].time;
			if(vis[to]) continue;
			if(tim[to]>p.n_dis+w)
			{
				tim[to]=p.n_dis+w;
				que.push((point){to,tim[to]});
				timnum[to]=timnum[p.id]+1;
				timpre[to]=p.id;
			}
			else if(tim[to]==p.n_dis+w)
			{
				if(timnum[p.id]+1<timnum[to])
				{
					timnum[to]=timnum[p.id]+1;
				    timpre[to]=p.id;
				}
			}
		}
	}
}
void get_timpath(ll x)
{
	while(timpre[x]!=-1) 
	{
		e2.push_back(x);
		x=timpre[x];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll v1,v2,one_way,len,ti;
		cin>>v1>>v2>>one_way>>len>>ti;
		e[v1].push_back((edge){v2,len,ti});
		if(!one_way) e[v2].push_back((edge){v1,len,ti});
	}
	cin>>st>>ed;
	dijkstra();
	get_dispath(ed);
    e1.push_back(st);
    dijkstra2();
    get_timpath(ed);
    e2.push_back(st);
    ll flag=0;
    if(e1.size()!=e2.size()) flag=1;
    else
    {
    	for(ll i=0;i<e1.size();i++)
    	{
    		if(e1[i]!=e2[i])
    		{
    			flag=1;
    			break;
			}
		} 	
	}
    if(flag) 
    {
    	cout<<"Time = "<<tim[ed]<<": ";
    	for(ll i=e2.size()-1;i>=0;i--) 
		{
			cout<<e2[i];
			if(i!=0) cout<<" => ";
		}
		cout<<"\n";
		cout<<"Distance = "<<dis[ed]<<": ";
    	for(ll i=e1.size()-1;i>=0;i--) 
		{
			cout<<e1[i];
			if(i!=0) cout<<" => ";
		}
	}
    else
    {
    	cout<<"Time = "<<tim[ed]<<"; Distance = "<<dis[ed]<<": ";
    	for(ll i=e1.size()-1;i>=0;i--) 
		{
			cout<<e1[i];
			if(i!=0) cout<<" => ";
		}
	}
	return 0;
}
