#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10;
struct point{
	ll x,y;
};
point p[N];
ll T;
bool cmp(point a,point b)
{
	if(a.x>b.x) return 1;
	if(a.x==b.x&&a.y>b.y) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		for(ll i=1;i<=4;i++) cin>>p[i].x>>p[i].y;
		sort(p+1,p+5,cmp);
		cout<<abs(p[1].x-p[3].x)*abs(p[1].y-p[2].y)<<"\n";
	}
	return 0;
}
