#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
struct node{
	ll time,suanli;
	bool operator <(const node &x) const
	{
		return time>x.time;
	}
};
priority_queue<node> q[N];
ll a,b,c,d,n,m,v[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>v[i];
	while(m--)
	{
		cin>>a>>b>>c>>d;
		while(!q[b].empty())
		{
			if(q[b].top().time<=a)
			{
				v[b]=v[b]+q[b].top().suanli;
				q[b].pop();
			}
			else break;
		}
		if(v[b]<d) cout<<"-1\n";
		else
		{
			q[b].push((node){a+c,d});
			v[b]=v[b]-d;
			cout<<v[b]<<"\n";
		}
	}
	return 0;
}
