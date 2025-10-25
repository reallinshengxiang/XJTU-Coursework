#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[35],t,n,h,o;
double ans;
void position(ll n,ll s,ll &x,ll &y)
{
	if(n==1)
	{
		if(s==1)  x=y=1;
		else if(s==2) 
		{
			x=1;
			y=2;
		}
		else if(s==3)  x=y=2;
		else
		{
			x=2;
			y=1;
		}
		return;
	}
	if(s<=p[n-1])  position(n-1,s,y,x);
	else if(s<=2*p[n-1])  
	{
		position(n-1,s-p[n-1],x,y);
		y=y+(1<<(n-1));
	}
	else if(s<=3*p[n-1])
	{
		position(n-1,s-2*p[n-1],x,y);
		x=x+(1<<(n-1));
		y=y+(1<<(n-1));
	}
	else
	{
		position(n-1,s-3*p[n-1],y,x);
		x=(1<<n)+1-x;
		y=(1<<(n-1))+1-y;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	p[1]=4;
	for(ll i=2;i<=33;i++) p[i]=4*p[i-1]; 
	while(t--)
	{
		ll x1,x2,y1,y2;
		cin>>n>>h>>o;
		position(n,h,x1,y1);
		position(n,o,x2,y2);
		ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*10;
		cout<<setprecision(0)<<fixed<<ans<<"\n";
	}
	return 0;
}
