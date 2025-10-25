#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Edge{
	ll to,nex;
};
Edge edge[30010];
ll head[30010],n,m,ans,cnt,x,y;
void addedge(ll x,ll y)
{
	cnt++;
	edge[cnt].to=y;
	edge[cnt].nex=head[x];
	head[x]=cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		addedge(x,y);
	}
	for(ll i=1;i<=n;i++)
	{
		ans=0;
		for(ll j=head[i];j;j=edge[j].nex)  ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
