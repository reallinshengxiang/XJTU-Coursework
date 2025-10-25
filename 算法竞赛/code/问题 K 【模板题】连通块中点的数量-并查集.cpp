#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[100010],s[100010];
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge_set(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y) 
	{
		s[y]=s[y]+s[x];
		f[x]=y;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,x,y;
    string ss;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		f[i]=i;
		s[i]=1;
	}
	while(m--)
	{
		cin>>ss>>x;
		if(ss=="C") 
		{
			cin>>y;
			merge_set(x,y);
		}
		else if(ss=="Q1")
		{
			cin>>y;
			if(find_set(x)==find_set(y)) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else
		{
			cout<<s[f[x]]<<"\n";
		}
	}	
	return 0;
}
