#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double x,y;
};
point a[100010],b[100010];
ll T,n;
bool cmp(point a,point b)
{
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
		for(ll i=1;i<=n;i++) cin>>b[i].x>>b[i].y; 
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		ll t=1;
		double ans=1e11;
		for(ll i=1;i<=n;i++)
		{
			while(t<=n-1&&cmp(a[t+1],b[i])) t++;
			for(ll j=t;j<=n;j++)
			{
				if(fabs(a[j].x-b[i].x)>ans) break;
				ans=min(ans,dis(a[j],b[i]));
			}
			for(ll j=t-1;j>=1;j--)
			{
				if(fabs(a[j].x-b[i].x)>ans) break;
				ans=min(ans,dis(a[j],b[i]));
			}
		}
		cout<<setprecision(3)<<fixed<<ans<<"\n";
	}
	return 0;
}
