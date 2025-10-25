#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll prime[N],vis[N],s[N],a,b,p,t,cnt,st,ans;
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	s[x]=y;
}
void euler(ll n)
{
	for(ll i=2;i<=n;i++)
	{
		if(!vis[i]) prime[++cnt]=i;
		for(ll j=1;j<=cnt;j++)
		{
			if(i*prime[j]>n) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>p;
	euler(b);
	for(ll i=a;i<=b;i++) s[i]=i;
	for(ll i=1;i<=cnt;i++)
	{
		if(prime[i]>=p) 
		{
			st=i;
			break;
		}
	}
	for(ll i=st;i<=cnt;i++)
	{
		t=0;
		while(t*prime[i]<a) t++;
		while(prime[i]*(t+1)<=b)
        {
            merge(prime[i]*t,prime[i]*(t+1));   
            t++;
        }
	}
	for(ll i=a;i<=b;i++) 
	{
		if(s[i]==i) ans++;
	}
	cout<<ans;
	return 0;
}
