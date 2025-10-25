#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=1e5+10;
ll sum[N],st[N],ed[N],pos[N],block,n,m,a[N],flag[N];
void update(ll l,ll r)
{
	ll p=pos[l],q=pos[r];
	if(p==q)
	{
		for(rll i=l;i<=r;i++) 
		{
			a[i]=1-a[i];
			if(a[i]==0) sum[p]--;
			else sum[p]++;
		}
	}
	else
	{
		for(rll i=l;i<=ed[p];i++) 
		{
			a[i]=1-a[i];
			if(a[i]==0) sum[p]--;
			else sum[p]++;
		}
		for(rll i=st[q];i<=r;i++) 
		{
			a[i]=1-a[i];
			if(a[i]==0) sum[q]--;
			else sum[q]++;
		}
		for(rll i=p+1;i<=q-1;i++) flag[i]++;
	}
}
ll ask(ll l,ll r)
{
	ll p=pos[l],q=pos[r],ans=0;
	if(p==q)
	{
		for(rll i=l;i<=r;i++) 
		{
			if(flag[p]%2&&!a[i]) ans++;
			else if(flag[p]%2==0&&a[i]) ans++;
		}
	}
	else
	{
		for(rll i=l;i<=ed[p];i++)
		{
			if(flag[p]%2&&!a[i]) ans++;
			else if(flag[p]%2==0&&a[i]) ans++;
		}
		for(rll i=st[q];i<=r;i++)
		{
			if(flag[q]%2&&!a[i]) ans++;
			else if(flag[q]%2==0&&a[i]) ans++;
		}
		for(rll i=p+1;i<=q-1;i++) 
		{
			if(flag[i]%2) ans=ans+block-sum[i];
			else ans=ans+sum[i];
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	block=sqrt(n);
	ll t=n/block;
	if(n%block) t++;
	for(ll i=1;i<=n;i++) pos[i]=(i-1)/block+1;
	for(rll i=1;i<=t;i++)
	{
		st[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	while(m--)
	{
		ll c,a,b;
		cin>>c>>a>>b;
		if(c==0) update(a,b);
		else if(c==1) cout<<ask(a,b)<<"\n";
	}
	return 0;
}
