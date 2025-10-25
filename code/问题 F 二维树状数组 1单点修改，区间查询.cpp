#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&-(x))
const ll N=5050;
ll tree[N][N],n,m;
void update(ll x,ll y,ll d)
{
	for(ll i=x;i<=n;i=i+lowbit(i))
	{
		for(ll j=y;j<=m;j=j+lowbit(j)) tree[i][j]=tree[i][j]+d;
	}
}
ll sum(ll x,ll y)
{
	ll ans=0;
	for(ll i=x;i>0;i=i-lowbit(i))
	{
		for(ll j=y;j>0;j=j-lowbit(j)) ans=ans+tree[i][j];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ll p,x,y,k,a,b,c,d;
	while(cin>>p)
	{		
		if(p==1)
		{
			cin>>x>>y>>k;
			update(x,y,k);
		}
		else
		{
			cin>>a>>b>>c>>d;
			k=sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1);
			cout<<k<<"\n";
		}
	}
	return 0;
} 
