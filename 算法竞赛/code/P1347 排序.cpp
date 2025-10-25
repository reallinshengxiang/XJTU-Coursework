#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=30;
ll a[N],vis[N],ans,n,m,x,y,indegree[N],degree[N],xx;
vector<ll> edge[N];
string s;
ll topo(ll x)
{
	ll cnt=0,flag=1;
	stack<ll> st;
	for(ll i=1;i<=n;i++)
	{
		degree[i]=indegree[i];
		if(degree[i]==0) 
		{
		    st.push(i);
			vis[i]=1;
		}
	}
	while(!st.empty())
	{
		if(st.size()>=2) flag=0;
		ll t=st.top();
		st.pop();
		cnt++;
		a[cnt]=t;
		for(ll i=0;i<edge[t].size();i++) degree[edge[t][i]]--;
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i]&&!degree[i])
			{
				st.push(i);
				vis[i]=1;
			}
		}
	}
	if(cnt<n) return 0;
	if(flag&&ans==0) ans=x;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		x=s[0]-'A'+1;
		y=s[2]-'A'+1;
		edge[x].push_back(y);
		indegree[y]++;
		memset(vis,0,sizeof(vis));
		xx=topo(i);
		if(ans!=0)
	    {   
		     cout<<"Sorted sequence determined after "<<ans<<" relations: ";
		     for(ll i=1;i<=n;i++) cout<<char(a[i]-1+'A');
		     cout<<".";
		     return 0;
	    }
		if(xx==0)
		{
			cout<<"Inconsistency found after "<<i<<" relations.";
			return 0;
		}
	}	
	cout<<"Sorted sequence cannot be determined.";
	return 0;
}
