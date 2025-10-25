#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=1e4+10;
const ld eps=1e-11;
ll n,m;
ld y,ans,sum[N],cha[N],xx[N],yy[N],mm[N];
ll check(ld x)
{
	ld ss=x;
	yy[1]=x;
	//cout<<yy[1]<<" ";
	for(ll i=2;i<=n+1;i++)
	{
		ld fm=yy[i-1]*yy[i-1]*sum[n+2-i]*sum[n+2-i];
		ld fz=(yy[i-1]*yy[i-1]+cha[i-1]*cha[i-1])*sum[n+1-i]*sum[n+1-i];
		//cout<<yy[i-1]<<"  "<<cha[i-1]<<"   "<<sum[n+1-i]<<"  "<<sum[n+2-i]<<"\n";
		//cout<<fm<<" "<<fz<<"\n";
		if(fz<=fm) return 1;
		yy[i]=sqrt(cha[i]*cha[i]/(fz/fm-1.0));
		ss=ss+yy[i];
		//cout<<yy[i]<<" ";
	}
	//cout<<ss<<"\n";
	if(ss>y) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>y;
	sum[0]=m;
	for(ll i=1;i<=n;i++) cin>>mm[i],sum[i]=sum[i-1]+mm[i];
	//for(ll i=0;i<=n;i++) cout<<sum[i]<<" ";
	//cout<<"\n";
	for(ll i=1;i<=n;i++) cin>>xx[i],cha[i]=fabs(xx[i]-xx[i-1]);
	xx[n+1]=2*xx[n];
	cha[n+1]=fabs(xx[n+1]-xx[n]);
	ld l=0,r=y;
	while(fabs(l-r)>eps)
	{
		ld mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	//cout<<yy[1]<<"\n";
	for(ll i=1;i<=n+1;i++) ans=ans+sqrt(cha[i]*cha[i]+yy[i]*yy[i])*sum[n+1-i];
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
/*
1 25 14
14
12
3 1 6
1 1 1
1 2 3
*/
