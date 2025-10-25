#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct cow{
	ll ss,ee,mm;
};
cow a[50050];
ll k,n,c,minn,ans,b[100100];
bool cmp(cow x,cow y)
{
	return ((x.ee<y.ee)||(x.ee==y.ee&&x.ss<y.ss));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n>>c;
	for(ll i=1;i<=k;i++) cin>>a[i].ss>>a[i].ee>>a[i].mm;
	sort(a+1,a+k+1,cmp);
	ans=0;
	for(ll i=1;i<=k;i++)
	{
		minn=0x7f;
		if(b[a[i].ss]<c)
		{
			for(ll j=a[i].ss;j<=a[i].ee-1;j++)
			{
				minn=min(minn,c-b[j]);
				if(minn==0) break;
			}
			if(minn!=0)
			{
				if(minn>=a[i].mm)
				{
					for(ll j=a[i].ss;j<=a[i].ee-1;j++)	b[j]=b[j]+a[i].mm;
					ans=ans+a[i].mm;
				}
				else 
				{
					for(ll j=a[i].ss;j<=a[i].ee-1;j++)	b[j]=b[j]+minn;
					ans=ans+minn;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
