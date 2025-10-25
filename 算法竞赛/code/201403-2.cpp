#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct photo
{
	ll x1,y1,x2,y2,id;
};
photo p[15];
ll n,m,x,y,pos;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) 
	{
		cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
		p[i].id=i;
	}
	while(m--)
	{
		cin>>x>>y;
		pos=0;
		for(ll i=n;i>=1;i--)
		{
			if(x>=p[i].x1&&x<=p[i].x2&&y>=p[i].y1&&y<=p[i].y2)
			{
				pos=i;
				break;
			}
		}
		if(pos==0)	cout<<"IGNORED\n";
		else
		{
			cout<<p[pos].id<<"\n";
			p[n+1]=p[pos];
			for(ll i=pos;i<=n;i++) p[i]=p[i+1];
		}
	}
	return 0;
}
