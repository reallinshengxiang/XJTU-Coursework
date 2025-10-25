#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll T,c[N],a[N],d[N],dis[N],m,l,r,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		c[1]=1;
		c[n]=-1;
		for(ll i=2;i<=n-1;i++) 
		{
			if(a[i]-a[i-1]<a[i+1]-a[i]) c[i]=-1;
			else c[i]=1;
		}
		dis[1]=0;
		for(ll i=2;i<=n;i++) 
		{
			if(c[i-1]==1) dis[i]=dis[i-1]+1;
			else dis[i]=dis[i-1]+abs(a[i]-a[i-1]);
		}
		d[n]=0;
		for(ll i=n-1;i>=1;i--)
		{
			if(c[i+1]==-1) d[i]=d[i+1]+1;
			else d[i]=d[i+1]+abs(a[i]-a[i+1]);
		}
		cin>>m;
		while(m--)
		{
			cin>>l>>r;
			if(l<r) cout<<dis[r]-dis[l]<<"\n";
			else cout<<d[r]-d[l]<<"\n";
		}
	}
	return 0; 
}
