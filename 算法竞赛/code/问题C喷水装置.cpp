#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double s,f;
};
point p[15010];
bool cmp(point a,point b)
{
	return a.s<b.s;
}
double l,w,r,x,endd,xx;
ll t,n,k,i,f,flag,tt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>w;
		tt=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>x>>r;
			if(r>w/2)
			{
			   tt++;
			   p[tt].s=x-sqrt(r*r-w*w/4);
			   p[tt].f=x+sqrt(r*r-w*w/4);				
			}
		}	
		sort(p+1,p+tt+1,cmp);
		endd=0;
		k=0;
		i=1;
		f=1;
		while(endd<l)
		{
			k++;
			double xx=endd;
			flag=0;
			while(i<=tt&&p[i].s<=xx)
			{
				endd=max(endd,p[i].f);
				i++;
			}
			if(xx==endd)
			{
				cout<<"-1\n";
				f=0;
				break;
			}
		}
		if(f) cout<<k<<"\n";
	}
	return 0;
}
