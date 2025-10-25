#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll s[N],n,m,ans; 
ll find_set(ll x)
{
	if(s[x]!=x) s[x]=find_set(s[x]);
	return s[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y) s[x]=y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		if(n==0) break;
		for(ll i=1;i<=n;i++) s[i]=i;
		cin>>m;
		for(ll i=1;i<=m;i++)
		{
			ll x,y;
			cin>>x>>y;
			merge(x,y);
		}
		ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(s[i]==i) ans++;
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
