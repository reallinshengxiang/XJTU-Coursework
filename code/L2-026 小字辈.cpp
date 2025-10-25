#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const ll N=1e5+10;
struct point{
	ll id,dis;
};
point p;
vector<ll> e[N];
deque<point> dq;
ll n,maxx,dis[N],x,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		e[x].push_back(i);
		if(x==-1) dq.push_back((point){i,1}),dis[i]=1;
	}
	while(!dq.empty())
	{
		p=dq.front();
		dq.pop_front();
		for(ll i=0;i<e[p.id].size();i++)
		{
			if(dis[e[p.id][i]]) continue;
			dis[e[p.id][i]]=p.dis+1;
			dq.push_back((point){e[p.id][i],p.dis+1});
		}
	}
	for(ll i=1;i<=n;i++) maxx=max(maxx,dis[i]);
	cout<<maxx<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(dis[i]==maxx)
		{
			if(!flag)
			{
				flag=1;
				cout<<i;
			}
			else cout<<" "<<i;
		}
	}
	return 0;
}
