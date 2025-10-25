#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll fa,c,t;
	double w;
};
node a[1010];
ll n,r,x,y,ans;
ll search()
{
	ll pos;
	double maxn=0;
	for(ll i=1; i<=n; i++)
	{
		if(a[i].w>maxn&&i!=r)
		{
			pos=i;
			maxn=a[i].w;
		}
	}
	return pos;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>r)
	{
		ans=0;
		if(n==0&&r==0) break;
		for(ll i=1; i<=n; i++)

		{
			cin>>a[i].c;
			a[i].w=a[i].c;
			a[i].t=1;
			ans=ans+a[i].c;
		}
		for(ll i=1; i<=n-1; i++)
		{
			cin>>x>>y;
			a[y].fa=x;
		}
		for(ll i=1; i<=n-1; i++)
		{
			ll pos=search();
			ll fa=a[pos].fa;
			a[pos].w=0;
			ans=ans+a[pos].c*a[fa].t;
			for(ll j=1; j<=n; j++)
			{
				if(a[j].fa==pos) a[j].fa=fa;
			}
			a[fa].c=a[fa].c+a[pos].c;
			a[fa].t=a[fa].t+a[pos].t;
			a[fa].w=a[fa].c*1.0/a[fa].t*1.0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
