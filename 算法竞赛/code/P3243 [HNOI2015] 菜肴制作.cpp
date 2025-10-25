#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=1e5+10;
ll n,m,degree[N],T,a[N];
vector<ll> edge[N];
void topo()
{
	ll cnt=0;
	priority_queue<ll> q;
	for(rll i=1;i<=n;i++)
	{
		if(degree[i]==0)  q.push(i);
	}
	while(!q.empty())
	{
		ll t=q.top();
		q.pop();
		cnt++;
		a[cnt]=t;
		for(rll i=0;i<edge[t].size();i++) 
		{
			degree[edge[t][i]]--;
			if(degree[edge[t][i]]==0) q.push(edge[t][i]);
		}
	}
	if(cnt<n) cout<<"Impossible!\n";
	else
	{
		for(rll i=n;i>=1;i--) cout<<a[i]<<" ";
		cout<<"\n"; 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		map<pair<ll,ll>,ll> mp;
		memset(degree,0,sizeof(degree));
		for(rll i=1;i<=m;i++)
		{
			ll x,y;
			cin>>y>>x;
			if(!mp[make_pair(x,y)])
			{
				mp[make_pair(x,y)]=1;
				edge[x].push_back(y);
			    degree[y]++;
			}		
		}
		topo();
		for(rll i=1;i<=n;i++) edge[i].clear();
	}
	return 0;
}
