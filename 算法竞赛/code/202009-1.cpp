#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
struct point{
	ll id,dis;
};
point p[N];
ll n,x,y,a,b;
bool cmp(point x,point y)
{
	if(x.dis<y.dis) return 1;
	if(x.dis==y.dis&&x.id<y.id) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>x>>y;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a>>b;
		p[i].dis=(a-x)*(a-x)+(b-y)*(b-y);
		p[i].id=i;
	}
	sort(p+1,p+n+1,cmp);
	for(ll i=1;i<=3;i++) cout<<p[i].id<<"\n";
	return 0;
}
