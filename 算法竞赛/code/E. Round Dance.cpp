#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll T,n,n1,n2,d[N],a[N],vis[N],flag;
vector<set<ll>> g(N);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			a[i]=d[i]=vis[i]=0;
			g[i].clear();
		}
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			g[i].insert(a[i]);
			g[a[i]].insert(i);
		}
		for(ll i=1;i<=n;i++) d[i]=g[i].size();
		n1=n2=0;
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				queue<ll> que;
				vector<ll> p;
				que.push(i);
				p.push_back(i);
				while(!que.empty())
				{
					ll u=que.front();
					que.pop();
					if(vis[u]) continue;
					vis[u]=1;
					for(ll v:g[u])
					{
						que.push(v);
						p.push_back(v);
					}
				}
				flag=0;
				for(ll j:p)
				{
					if(d[j]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag) n1++;
				else n2++;
			}
		}
		cout<<n2+min((ll)1,n1)<<" "<<n1+n2<<"\n";
	}
	return 0; 
}
