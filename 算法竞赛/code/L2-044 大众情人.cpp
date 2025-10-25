#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
struct peo{
	ll id,dis;
};
peo a[N],b[N];
map<ll,ll> mp1,mp2;
ll n,dis[N][N];
char ch;
bool cmp(peo x,peo y)
{
	if(x.dis<y.dis) return 1;
	if(x.dis==y.dis&&x.id<y.id) return 1;
	return 0;
}
int main()
{
	cin>>n;
	memset(dis,127/3,sizeof(dis));
	ll inf=dis[0][0];
	for(ll i=1;i<=n;i++) a[i].id=b[i].id=i,a[i].dis=b[i].dis=inf;
	for(ll i=1;i<=n;i++)
	{
		ll nn;
		cin>>ch>>nn;
		if(ch=='F')	mp1[i]=1;
		else mp2[i]=1;
		for(ll j=1;j<=nn;j++)
		{
			ll x,y;
			cin>>x>>ch>>y;
			dis[i][x]=y;
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++) 
			{
				if(i==k||i==j||i==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		ll flag=0;
		if(mp1[i])
		{
			for(ll j=1;j<=n;j++) 
			{
				if(j==i) continue;
				if(mp2[j]&&!flag) a[i].dis=dis[j][i],flag=1;
				if(mp2[j]&&flag) a[i].dis=max(a[i].dis,dis[j][i]);
			}
		}
		else if(mp2[i])
		{
			for(ll j=1;j<=n;j++)
			{
				if(j==i) continue;
				if(mp1[j]&&!flag) b[i].dis=dis[j][i],flag=1;
				if(mp1[j]&&flag) b[i].dis=max(b[i].dis,dis[j][i]);
			}
		}		
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	ll minn1=a[1].dis;
	ll minn2=b[1].dis;
	ll ff=0;
	for(ll i=1;i<=n;i++)
	{
		if(!mp1[a[i].id]) continue;
		if(a[i].dis==minn1&&!ff) cout<<a[i].id,ff=1;
		else if(a[i].dis==minn1&&ff) cout<<" "<<a[i].id;
		else break;
	}
	cout<<"\n";
	ff=0;
	for(ll i=1;i<=n;i++)
	{
		if(!mp2[b[i].id]) continue;
		if(b[i].dis==minn2&&!ff) cout<<b[i].id,ff=1;
		else if(b[i].dis==minn2&&ff) cout<<" "<<b[i].id;
		else break;
	}
}
