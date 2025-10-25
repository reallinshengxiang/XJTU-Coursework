#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double x,y;
	point(const double &xx=0,const double &yy=0):x(xx),y(yy){};
	point operator+(const point &a){ return point(x+a.x,y+a.y);}
	point operator-(const point &a){ return point(x-a.x,y-a.y);}
	point operator*(const double &a){ return point(x*a,y*a);}
	point operator/(const double &a){ return point(x/a,y/a);}
};
point a,b,c,d;
double pp,rr,qq;
double dis(point aa,point bb)
{
	return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));
}
double calc(point x)
{
	point lmid,rmid,l=c,r=d;
	double ans1,ans2;
	while(dis(l,r)>=0.0000001)
	{
		lmid=l+(r-l)/3;
		rmid=r-(r-l)/3;
		ans1=dis(x,lmid)/rr+dis(lmid,d)/qq;
		ans2=dis(x,rmid)/rr+dis(rmid,d)/qq;
		if(ans1<ans2) r=rmid;
		else l=lmid;
	}
	return dis(l,x)/rr+dis(l,d)/qq;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>pp>>qq>>rr;		
	point lmid,rmid,l=a,r=b;	
	
	while(dis(l,r)>=0.0000001)
	{
		lmid=l+(r-l)/3;
		rmid=r-(r-l)/3;		
		double ans1=calc(lmid)+dis(a,lmid)/pp;
		double ans2=calc(rmid)+dis(a,rmid)/pp;
		if(ans1<ans2) r=rmid;
		else l=lmid;
	}
	cout<<fixed<<setprecision(2)<<dis(a,l)/pp+calc(l);
	return 0;
}
