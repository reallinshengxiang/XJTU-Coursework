#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=1e5+10;
struct Theta
{
	ld l,r;
};
Theta theta[N];
ld x,y,r,ans;
ll cnt,n;
bool cmp(Theta x,Theta y)
{
	if(x.l<y.l) return 1;
	if(x.l==y.l&&x.r<y.r) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x>>y>>r;
		cnt++;
		theta[cnt].l=atan(y/x)-asin(r/sqrt(x*x+y*y)); 
		theta[cnt].r=atan(y/x)+asin(r/sqrt(x*x+y*y)); 
		if(theta[cnt].l<=0) theta[cnt].l=0;
		if(theta[cnt].l>=atan(1)*2) theta[cnt].l=atan(1)*2;
		if(theta[cnt].r<=0) theta[cnt].r=0;
		if(theta[cnt].r>=atan(1)*2) theta[cnt].r=atan(1)*2;
	}
	sort(theta+1,theta+cnt+1,cmp);
/*	for(ll i=1;i<=cnt;i++)
	{
		cout<<theta[i].l<<"  "<<theta[i].r<<"\n";
	}*/
	ld ed=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(theta[i].r<ed) continue;
		else
		{
			ans=ans+theta[i].r-max(ed,theta[i].l);
			ed=theta[i].r;
		}
	}
	cout<<fixed<<setprecision(3)<<1-ans/(atan(1))/2; 
	return 0;
}
