#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e4+10;
ll s[N],n,m,opt,b[N],ans[N],a,y,p,t;
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) s[i]=i;
	while(m--)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>a>>y;
			a=find_set(a);
			y=find_set(y);
			if(a==y) continue;
			for(ll i=1;i<=n;i++) ans[i]=ans[i]+b[find_set(i)];
			memset(b,0,sizeof(b));
			s[a]=y;
		}
		else if(opt==2)
		{
			cin>>p>>t;
			p=find_set(p);
			b[p]=b[p]+t;
		}
	}
	for(ll i=1;i<=n;i++) cout<<ans[i]+b[find_set(i)]<<" ";
	return 0;
}
