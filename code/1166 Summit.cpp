#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220;
ll x,y,a[N][N],n,m,k,l,pos,vis[N],xx[N];
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) a[i][i]=1;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	cin>>k;
	for(ll i=1;i<=k;i++)
	{
		cin>>l;
		for(ll q=1;q<=n;q++) vis[q]=0;
		mp.clear();
		for(ll j=1;j<=l;j++)
		{
			cin>>xx[j];
			mp[xx[j]]=1;
			for(ll q=1;q<=n;q++)
			{
				if(a[xx[j]][q]) vis[q]++;
			}
		}
		ll flag=0;
		for(ll j=1;j<=l;j++)
		{
			if(vis[xx[j]]!=l)
			{
			//	cout<<xx[j]<<"  "<<vis[xx[j]]<<"\n";
				flag=4;
				break;
			} 
		}
		if(flag==4) 
		{
			cout<<"Area "<<i<<" needs help.";
			if(i!=k) cout<<"\n";
			continue;
		}
		for(ll q=1;q<=n;q++)
		{
			if(vis[q]==l&&!mp[q])
			{
				flag=3;
				pos=q;
				break;
			}
		}
		if(flag==3)
		{
			cout<<"Area "<<i<<" may invite more people, such as "<<pos<<".";
			if(i!=k) cout<<"\n";
			continue;
		}
		if(!flag)
		{
			cout<<"Area "<<i<<" is OK.";
			if(i!=k) cout<<"\n";
		}
	}
	return 0;
}
