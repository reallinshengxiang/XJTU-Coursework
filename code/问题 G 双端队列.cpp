#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Shu{
	ll num,pos;
};
Shu a[200010];
bool cmp(Shu xx,Shu yy)
{
	if(xx.num==yy.num)  return xx.pos<yy.pos;
	return xx.num<yy.num;
}
int main()
{
	ll minn=0x3f3f3f3f,maxx=-minn,n,x1=1,x2,flag=0,ans=1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].num;
		a[i].pos=i; 
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		if(a[i].num!=a[i+1].num)
		{
			x2=i;
			if(flag==0)
			{
				if(a[x2].pos<=minn) minn=a[x1].pos;
				else
				{
					flag=1-flag;
					maxx=a[x2].pos;
				}
			}
			else
			{
				if(a[x1].pos<=maxx)
				{
					ans++;
					flag=1-flag;
					minn=a[x1].pos;
				}
				else  maxx=a[x2].pos;
			}
			x1=i+1; 
		}
		
	}
	cout<<ans;
	return 0;
} 
