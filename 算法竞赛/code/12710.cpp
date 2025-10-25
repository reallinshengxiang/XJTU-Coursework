#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
struct point {
	ll x,y;
	bool operator < (const point a) const {
		if(a.x!=x) return a.x<x;
		if(a.y!=y) return a.y<y;
	}
}; 
const ll N=1e5+10;
string s;
ll n,a[N],x,y,sum[N][5],num,ans;
map<point,ll> vis;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	a[0]=0;
	for(ll i=0;i<n;i++) 
	{
		if(s[i]=='F') a[i+1]=a[i];
		else if(s[i]=='L') a[i+1]=(a[i]+3)%4;
		else if(s[i]=='R') a[i+1]=(a[i]+1)%4;
	}
	for(ll i=1;i<=n;i++) 
	{
		for(ll j=0;j<=3;j++) sum[i][j]=sum[i-1][j];
		sum[i][a[i]]++;
	}
	cout<<sum[n][2]-sum[n][0]<<"  "<<sum[n][1]-sum[n][3]<<"\n";
	vis[(point){sum[n][1]-sum[n][3],sum[n][2]-sum[n][0]}]=1;
	for(ll i=1;i<=n;i++)
	{
		ll px=sum[i-1][1]-sum[i-1][3];
		ll py=sum[i-1][2]-sum[i-1][0];
		ll dx1=sum[n][2]-sum[i][0];
		ll dy1=sum[n][3]-sum[i][1];
		ll dx2=sum[n][0]-sum[i][2];
		ll dy2=sum[n][1]-sum[i][3];
		ll dx3=sum[n][3]-sum[i][1];
		ll dy3=sum[n][0]-sum[i][2];
		if(a[i]==0)
		{
			ll now_x=px+dx1-1;
			ll now_y=py+dy1-1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx2+1;
			now_y=py+dy2-1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx3;
			now_y=py+dy3-2;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
		}
		else if(a[i]==1)
		{
			ll now_x=px+dx1-1;
			ll now_y=py+dy1-1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx2-1;
			now_y=py+dy2+1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx1-2;
			now_y=py+dy1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
		}
		else if(a[i]==2)
		{
			ll now_x=px+dx1+1;
			ll now_y=py+dy1+1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx2-1;
			now_y=py+dy2+1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx3;
			now_y=py+dy3+2;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
		}
		else if(a[i]==3)
		{
			ll now_x=px+dx1+1;
			ll now_y=py+dy1+1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx2+1;
			now_y=py+dy2-1;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
			now_x=px+dx1+2;
			now_y=py+dy3;
			if(vis[(point{now_x,now_y})]!=1) ans++,vis[(point{now_x,now_y})]=1;
		}
	}
	cout<<ans;
	return 0;
} 
