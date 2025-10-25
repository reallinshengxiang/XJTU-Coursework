#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll xx,yy,ee;
};
node p[100010];
ll flag,T,n,cnt;
unordered_map<ll,ll> f;
ll find_set(ll x)
{
	if(f[x]!=x) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	f[x]=y;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		f.clear();
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>p[i].xx>>p[i].yy>>p[i].ee;
			if(f[p[i].xx]==0)	f[p[i].xx]=p[i].xx;
			if(f[p[i].yy]==0)	f[p[i].yy]=p[i].yy;
		}
		flag=1;
		for(ll i=1;i<=n;i++)
		{
			if(p[i].ee) 	merge(p[i].xx,p[i].yy);
		}
		for(ll i=1;i<=n&&flag;i++)
		{
			if(p[i].ee==0&&find_set(p[i].xx)==find_set(p[i].yy))
			{
				cout<<"NO\n";
				flag=0;
			}
		}
		if(flag)  cout<<"YES\n";
	}
	return 0;
}
