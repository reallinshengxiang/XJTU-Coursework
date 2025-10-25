#include<bits/stdc++.h>
using namespace std;
#define ll long  double
ll js(ll y1,ll xx,ll yy,ll x2,ll x1)
{
	return sqrt(x2*x2+yy*yy)+sqrt((y1-xx-yy*x1/x2)*(y1-xx-yy*x1/x2)+yy*yy*xx*xx/x2/x2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long double x1,x2,y1,y2,yy,xx,x01,x02,x03;
	cin>>x1>>y1>>x2>>y2;
	if(x1*y1<x2*y2) 
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	if(x1<y1) swap(x1,y1);
	if(x2<y2) swap(x2,y2);
	if(x1>=x2&&y1>=y2)
	{
		cout<<"Yes";
		return 0;
	} 
	if(x1<x2&&x2*x2<=x1*x1+y1*y1)
	{
		xx=sqrt(x2*x2-x1*x1);
		x01=y2*x1/x2;
		x02=y2*xx/x2;
		long double k=(x01+xx)*x02/(x1-x02);
		if(k+x01+xx<=y1) 
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";	
	return 0;
}
