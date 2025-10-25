#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	double x,y,z;
};
bool cmp(point a,point b)
{
	return a.z<b.z;
}
point a[50005];
int main()
{
	double ans=0;
	ll n,i; 
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+n+1,cmp);
	for(i=2;i<=n;i++)	ans=ans+sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+(a[i].y-a[i-1].y)*(a[i].y-a[i-1].y)+(a[i].z-a[i-1].z)*(a[i].z-a[i-1].z));
	cout<<fixed<<setprecision(3)<<ans;
}
