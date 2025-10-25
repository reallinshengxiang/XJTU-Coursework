#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=220;
ll e[N][N],n,m,k,vis[N],x,y,minn=1e10,minid,w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		e[x][y]=e[y][x]=w;
	}
	cin>>k;
	for(ll ii=1;ii<=k;ii++)
	{
		ll nn,sum=0;
		cin>>nn;
		for(ll i=1;i<=n;i++) vis[i]=0;
		ll flag=1,st,ed;
		cout<<"Path "<<ii<<": ";
		for(ll i=1;i<=nn;i++)
		{
			cin>>x;
			if(i==1) st=x;
			if(i==nn) ed=x;
			vis[x]++;
			if(i!=1) 
			{
				if(!e[x][y]) flag=0;
				sum=sum+e[x][y];
			}
			y=x;
		}
		if(!flag) cout<<"NA ";
		else cout<<sum<<" ";	
		ll f1=1,f2=0,cnt=0;
		for(ll i=1;i<=n;i++)
		{
			if(vis[i]==0) f1=0; 
			if(vis[i]==2) cnt++;
			if(vis[i]>2) f2=1;
		}
		if(!flag||(st!=ed)||!f1||(!cnt&&!f2)) cout<<"(Not a TS cycle)";
		else if(cnt>=1&&f2)cout<<"(TS cycle)";
		else  cout<<"(TS simple cycle)";	
		cout<<"\n";
		if(f1&&flag)
		{
			if(minn>sum) minn=sum,minid=ii; 
		} 
	}
	cout<<"Shortest Dist("<<minid<<") = "<<minn;
	return 0;
}
