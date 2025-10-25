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
	//cout<<sum[n][2]-sum[n][0]<<"  "<<sum[n][1]-sum[n][3]<<"\n";
	//vis[(point){sum[n][1]-sum[n][3],sum[n][2]-sum[n][0]}]=1;
	for(ll i=1;i<=n;i++)
	{
		//cout<<i<<"\n";
		ll px=sum[i][1]-sum[i][3];
		ll py=sum[i][2]-sum[i][0];
		
		ll dx1=sum[n][2]-sum[i][2]-sum[n][0]+sum[i][0];
		ll dy1=sum[n][3]-sum[i][3]-sum[n][1]+sum[i][1];  //左转一次 ，右转三次 
		
		ll dx2=sum[n][0]-sum[i][0]-sum[n][2]+sum[i][2];
		ll dy2=sum[n][1]-sum[i][1]-sum[n][3]+sum[i][3];  //左转三次，右转一次 
		
		ll dx3=sum[n][3]-sum[i][3]-sum[n][1]+sum[i][1];
		ll dy3=sum[n][0]-sum[i][0]-sum[n][2]+sum[i][2];  //右转两次 ，左转两次 
		//cout<<a[i]<<"  "<<py<<"   "<<px<< "\n";
		ll now_x,now_y;
		if(s[i-1]=='F')
		{
			//F->L 左转一次 
			now_x=px+dx1; 
			now_y=py+dy1;
			if(a[i]==0) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==1) now_x=now_x-1,now_y=now_y-1;
			else if(a[i]==2) now_x=now_x+1,now_y=now_y-1;
			else if(a[i]==3) now_x=now_x+1,now_y=now_y+1;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
			//F->R 右转一次 
			now_x=px+dx2;
			now_y=py+dy2;
			if(a[i]==0) now_x=now_x+1,now_y=now_y+1;
			else if(a[i]==1) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==2) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==3) now_x=now_x+1,now_y=now_y-1;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;	
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
		} 
		else if(s[i-1]=='L')
		{
			//L->F 右转一次 
			now_x=px+dx2;
			now_y=py+dy2;
			if(a[i]==0) now_x=now_x+1,now_y=now_y+1;
			else if(a[i]==1) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==2) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==3) now_x=now_x+1,now_y=now_y-1;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;	
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
			//L->R 右转两次 
			now_x=px+dx3;
			now_y=py+dy3;
			if(a[i]==0) now_x=now_x,now_y=now_y+2;
			else if(a[i]==1) now_x=now_x-2,now_y=now_y;
			else if(a[i]==2) now_x=now_x,now_y=now_y-2;
			else if(a[i]==3) now_x=now_x+2,now_y=now_y;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;	
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
		} 
		else if(s[i-1]=='R')
		{
			//R->L 左转两次 
			now_x=px+dx3;
			now_y=py+dy3;
			if(a[i]==0) now_x=now_x,now_y=now_y+2;
			else if(a[i]==1) now_x=now_x-2,now_y=now_y;
			else if(a[i]==2) now_x=now_x,now_y=now_y-2;
			else if(a[i]==3) now_x=now_x+2,now_y=now_y;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;	
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
			//R->F 左转一次 
			now_x=px+dx1; 
			now_y=py+dy1;
			if(a[i]==0) now_x=now_x-1,now_y=now_y+1;
			else if(a[i]==1) now_x=now_x-1,now_y=now_y-1;
			else if(a[i]==2) now_x=now_x+1,now_y=now_y-1;
			else if(a[i]==3) now_x=now_x+1,now_y=now_y+1;
			if(vis[(point){now_y,now_x}]!=1) vis[(point){now_y,now_x}]=1,ans++;
			//cout<<s[i-1]<<"   "<<a[i]<<"    "<<now_y<<"  "<<now_x<<"\n";
		} 
	}
	cout<<ans;
	return 0;
} 
