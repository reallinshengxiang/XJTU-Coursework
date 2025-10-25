#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double x,y;
};
point p[1010];
struct line
{
	double k,b;
};
ll cnt,n,m,flag;
double kk,bb; 
line l[200200];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cnt=(i-1)*m+j;
			p[cnt].x=(double)i;
			p[cnt].y=(double)j;
		}
	}
	cnt=0;
	for(ll i=1;i<=n*m-1;i++)
	{
		for(ll j=i+1;j<=n*m;j++)
		{
			kk=(p[i].y-p[j].y)/(p[i].x-p[j].x);
			bb=p[j].y-kk*p[j].x;
			if(p[i].x==p[j].x)   
			{
				kk=123456789;
				bb=-123456789+p[i].x;
			}
			flag=1;
			for(ll q=1;q<=cnt;q++)
			{
			    if((abs(l[q].b-bb)<=1e-7)&&(abs(l[q].k-kk)<=1e-7))
			    {
			    	flag=0;
			    	break;
				}
			}
			if(flag)
			{
				cnt++;
				l[cnt].b=bb;
				l[cnt].k=kk;
			}
		}
	}
	for(ll i=1;i<=cnt;i++)
	{
		cout<<l[i].k<<"  "<<l[i].b<<"\n";
	}
	cout<<cnt;
	return 0;
}
