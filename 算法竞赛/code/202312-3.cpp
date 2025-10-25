#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e3+10;
struct point{
	ll w,id;
};
point p[N];
ll n,m;
bool cmp(point a,point b)
{
	if(a.w>b.w) return 1;
	if(a.w==b.w&&a.id<b.id) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>p[i].w,p[i].id=i;
	sort(p+1,p+n+1,cmp);
    for(ll i=1;i<=n;i++) cout<<p[i].w<<"  "<<p[i].id<<"\n";
	return 0;
 } 
