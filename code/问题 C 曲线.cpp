#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],b[100010],c[100010],t,n;
double check(double x)
{
	double maxx=a[1]*x*x+b[1]*x+c[1];
	for(ll i=2;i<=n;i++)	maxx=max(maxx,a[i]*x*x+b[i]*x+c[i]);
	return maxx;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		double l=0,r=1000;
		while(r-l>=0.00000000001)
		{
			double rmid=r-(r-l)/3,lmid=l+(r-l)/3;
			if(check(lmid)>check(rmid)) l=lmid;
			else r=rmid;
		}
		cout<<fixed<<setprecision(4)<<check(l)<<"\n";
	} 
	return 0;
 } 
