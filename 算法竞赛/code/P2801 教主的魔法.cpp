#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=1e6+10,M=1e3+10;
ll a[N],b[N],n,q,pos[N],ed[M],st[M],add[M];
void change(ll l,ll r,ll d)
{
	ll p=pos[l],q=pos[r];
	if(p==q)
	{
		for(rll i=l;i<=r;i++) a[i]=a[i]+d;
		for(rll i=st[p];i<=ed[p];i++) b[i]=a[i];
		sort(b+st[p],b+ed[p]+1);
	}
	else
	{
		for(rll i=l;i<=ed[p];i++) a[i]=a[i]+d;
		for(rll i=st[p];i<=ed[p];i++) b[i]=a[i];
		sort(b+st[p],b+ed[p]+1);
		for(rll i=st[q];i<=r;i++) a[i]=a[i]+d;
		for(rll i=st[q];i<=ed[q];i++) b[i]=a[i];
		sort(b+st[q],b+ed[q]+1);
		for(rll i=p+1;i<=q-1;i++) add[i]=add[i]+d;
	}
} 
ll ask(ll l,ll r,ll c)
{
	ll p=pos[l],q=pos[r],ans=0;
	if(p==q)
	{
		for(rll i=l;i<=r;i++)
		{
			if(add[p]+a[i]>=c) ans++;
		}
	}
	else
	{
		for(rll i=l;i<=ed[p];i++)
		{
			if(add[p]+a[i]>=c) ans++;
		}
		for(rll i=st[q];i<=r;i++)
		{
			if(add[q]+a[i]>=c) ans++;
		}
		for(rll i=p+1;i<=q-1;i++)
		{
			ll pl=st[i],pr=ed[i],xx=0,mid;
			while(pl<=pr)
			{   
				mid=(pl+pr)>>1;
				if(add[i]+b[mid]>=c) pr=mid-1,xx=ed[i]-mid+1;
				else pl=mid+1;
			}
			ans=ans+xx;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	ll block=sqrt(n);
	ll t=n/block;
	if(n%block) t++;
	for(rll i=1;i<=t;i++)
	{
		st[i]=(i-1)*block+1;
		ed[i]=i*block;
	}
	ed[t]=n;
	for(rll i=1;i<=n;i++) pos[i]=(i-1)/block+1;
	for(rll i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	for(rll i=1;i<=t;i++) sort(b+st[i],b+ed[i]+1);
	while(q--)
	{
		char ch;
		ll l,r,w,c;
		cin>>ch;
		if(ch=='M')
		{
			cin>>l>>r>>w;
			change(l,r,w);
		}
		else if(ch=='A')
		{
			cin>>l>>r>>c;
			cout<<ask(l,r,c)<<"\n";
		}
	}
	return 0;
} 
