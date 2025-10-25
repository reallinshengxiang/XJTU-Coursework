#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
struct hole{
	ll x,y,z;
};
hole a[N];
ll T,n,h,r,cnt1,cnt2,top[N],bottom[N],flag,f[N];
ll find_set(ll x)
{
	if(f[x]!=x) f[x]=find_set(f[x]);
	return f[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>h>>r;
		for(ll i=1;i<=n;i++) f[i]=i;
		cnt1=cnt2=0;
		for(ll i=1;i<=n;i++) 
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z+r>=h)
			{
				cnt1++;
				top[cnt1]=i;
			}
			if(a[i].z-r<=0)
			{
				cnt2++;
				bottom[cnt2]=i;
			}
			for(ll j=1;j<=i-1;j++)
			{
				if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z)<=4*r*r)
				{
					ll x=find_set(i);
					ll y=find_set(j);
					if(x!=y) f[x]=y;
				}
			}
		}
		flag=0;
		for(ll i=1;i<=cnt1;i++)
		{
			for(ll j=1;j<=cnt2;j++)
			{
				if(find_set(top[i])==find_set(bottom[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
