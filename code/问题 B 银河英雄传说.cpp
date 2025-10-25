#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e4+10;
ll wz[N],f[N],sum[N],T;
ll find_set(ll x)
{
	if(f[x]!=x)
	{
		ll fa=find_set(f[x]); 
		wz[x]=wz[x]+wz[f[x]];
	    f[x]=fa;
	}	
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	f[x]=y;
	wz[x]=wz[x]+sum[y];
	sum[y]=sum[y]+sum[x];
	sum[x]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=N-1;i++)
	{
		f[i]=i;
		sum[i]=1;
	}
	cin>>T;
	while(T--)
	{
		char ch;
		ll x,y;
		cin>>ch>>x>>y;
		if(ch=='M') merge(x,y);
		else 
		{
			if(find_set(x)==find_set(y)) cout<<(abs(wz[x]-wz[y])-1)<<"\n";
			else cout<<"-1\n";
		}
	} 
	return 0;
}
