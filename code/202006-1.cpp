#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct point{
	ll x,y,type;
};
point p[N];
char ch;
ll n,m,pos;
bool cmp(point a,point b)
{
	if(a.type<b.type) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y>>ch;
		if(ch=='B') p[i].type=1;
		else pos++;
	}
	sort(p+1,p+n+1,cmp);
	while(m--)
	{
		ll a1,a2,a3,f1,f2,flag;
		cin>>a1>>a2>>a3;
		if(pos==n)
		{
			cout<<"Yes\n";
			continue;
		}
		f1=a1+a2*p[1].x+a3*p[1].y;
		f2=a1+a2*p[pos+1].x+a3*p[pos+1].y;
		if(f1*f2>=0)
		{
			cout<<"No\n";
			continue;
		}
		flag=1;
		for(ll i=2;i<=pos;i++)
		{
			if(f1>0&&a1+a2*p[i].x+a3*p[i].y<=0)
			{
				flag=0;
				break;
			}
			else if(f1<0&&a1+a2*p[i].x+a3*p[i].y>=0)
			{
				flag=0;
				break;
			}
		}		
		if(!flag)
		{
			cout<<"No\n";
			continue;
		}
		for(ll i=pos+2;i<=n;i++)
		{
			if(f2>0&&a1+a2*p[i].x+a3*p[i].y<=0)
			{
				flag=0;
				break;
			}
			else if(f2<0&&a1+a2*p[i].x+a3*p[i].y>=0)
			{
				flag=0;
				break;
			} 
		}		
		if(!flag)	cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
/*
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
0 1 A
3 1 B
1 3 B
2 0 A
2 3 B
0 2 -3
-3 0 2
-3 1 1
*/
