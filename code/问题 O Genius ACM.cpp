#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll st,ed,n,m,k,a[N],b[N],c[N],t,ans,p;
void merge(ll l,ll mid,ll r)
{
	ll i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(c[i]<=c[j])
		{
			b[k]=c[i];
			k++;
			i++;	        
		}
		else
		{
			b[k]=c[j];
			k++;
			j++;
		}
	}
	while(j<=r)
	{
		b[k]=c[j];
		k++;
		j++;
	}
	while(i<=mid)
	{
		b[k]=c[i];
		k++;
		i++;
	}
}
bool check(ll st,ll mid,ll ed)
{
	for(ll i=mid+1;i<=ed;i++)	c[i]=a[i];
	sort(c+mid+1,c+ed+1);
	merge(st,mid,ed);
	ll sum=0;
	for(ll i=1;i<=(ed-st+1)>>1&&i<=m;i++)   sum=sum+(b[ed-i+1]-b[st+i-1])*(b[ed-i+1]-b[st+i-1]);
	if(sum<=k)
	{
		for(ll i=st;i<=ed;i++) c[i]=b[i];
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(ll i=1;i<=n;i++) cin>>a[i];
		ans=0;
		st=ed=1;
		p=n-1;
		c[1]=a[1];
		while(ed<=n)
		{
			if(p==0)
			{
				p=1;
				ans++;
				st=ed+1;
				ed++;
				c[st]=a[st];
			}
			else if(ed+p<=n&&check(st,ed,ed+p))
			{
				ed=ed+p;
				p<<=1;
				if(ed==n) break;
			}
			else p>>=1;
			
		}
		if(ed==n) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
