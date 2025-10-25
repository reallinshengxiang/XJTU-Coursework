#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[100010];
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge_set(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y) f[x]=f[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,x,y;
    char ch;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) f[i]=i;
	while(m--)
	{
		cin>>ch>>x>>y;
		if(ch=='M') merge_set(x,y);
		else 
		{
			if(find_set(x)==find_set(y)) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
