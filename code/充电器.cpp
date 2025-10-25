#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,h,m,s,u,t,lastu,last,now,ans,lastt;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld:%lld:%lld %lld %lld",&h,&m,&s,&u,&t);
		now=h*3600+m*60+s;
		if(i!=1)  ans=ans+lastu*lastt*(now-last);
		lastu=u;
		lastt=t;
		last=now;
	}
	printf("%lld",ans);
	return 0; 
}
