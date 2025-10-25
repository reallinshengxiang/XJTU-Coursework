#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10010;
ll low[N],num[N],scc[N],st[N],dfn,top,cnt,n,m,a,b,ans,flag,t;
vector<ll> g[N],s[N];
void dfs(ll a)
{
	st[top]=a;
	top++;
	dfn++;
	low[a]=num[a]=dfn;
	for(ll i=0;i<g[a].size();i++)
	{
		ll b=g[a][i];
		if(!num[b])
		{
			dfs(b);
			low[a]=min(low[b],low[a]);
		}
		else if(!scc[b])   low[a]=min(low[a],num[b]);
		
	}
	if(low[a]==num[a])
	{
		cnt++;
		while(1)
		{
			top--;
			ll b=st[top];
			scc[b]=cnt;
			if(s[cnt].empty()) s[cnt].push_back(1);
			else s[cnt][0]++;
			s[cnt].push_back(b);		
			if(a==b) break;
	    }
	}
}
void tarjan(ll n)
{
	cnt=top=dfn=0;
	memset(scc,0,sizeof(scc));
    memset(num,0,sizeof(num));
    memset(low,0,sizeof(low));
    for(ll i=1;i<=n;i++)
    {
    	if(!num[i]) dfs(i);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b;
		g[a].push_back(b);
	}
	tarjan(n);
	ans=0;
	for(ll i=1;i<=cnt;i++)
	{    
		flag=1;
		for(ll j=1;j<=s[i][0];j++)
		{
			for(ll k=0;k<g[s[i][j]].size();k++)
			{
				if(scc[s[i][j]]!=scc[g[s[i][j]][k]]) 
				{
					flag=0;
					break;
				}
			}
		}
		if(flag) 
		{
		   ans=i;
		   t++;	
		}
	}
	if(t>=2) cout<<0;
	else if(ans==0) cout<<0;
	else  cout<<s[ans][0]; 
	return 0;
}
