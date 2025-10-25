#include<bits/stdc++.h>
using namespace std;
#define ll long long
double ans,H,h,D,x;
ll t;
double check(double x)
{
	if((H-h)/x*(D-x)>h) return x/(H-h)*h;
	else return D-x+h-(H-h)/x*(D-x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>H>>h>>D;
		double l=0,r=D;
		while(r-l>=0.000000001)
		{
			double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
			if(check(lmid)>check(rmid)) r=rmid;
			else l=lmid;
		}
		cout<<fixed<<setprecision(3)<<check(l)<<"\n";
	}
	return 0;
}
