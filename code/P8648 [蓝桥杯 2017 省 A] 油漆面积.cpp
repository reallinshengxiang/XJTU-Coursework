#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+10;
struct scanline{
	ll y,left_x,right_x,inout;
	scanline(){};
	scanline(ll y,ll left_x,ll right_x,ll inout):y(y),left_x(left_x),right_x(right_x),inout(inout){}
};
scanline line[N];
ll tag[N],length[N],xx[N],cnt,n,ans;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
bool cmp(const scanline &a,const scanline &b){return a.y<b.y;}
void push_up(ll p,ll pl,ll pr)
{
	if(tag[p]) length[p]=xx[pr]-xx[pl];
	else if(pl+1==pr) length[p]=0;
	else length[p]=length[ls(p)]+length[rs(p)];
}
void update(ll l,ll r,ll io,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr)
	{
		tag[p]=tag[p]+io;
		push_up(p,pl,pr);
		return;
	}
	if(pl+1==pr) return;
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,io,ls(p),pl,mid);
	if(r>mid) update(l,r,io,rs(p),mid,pr);
	push_up(p,pl,pr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		line[++cnt]=scanline(y1,x1,x2,1);
		xx[cnt]=x1;
		line[++cnt]=scanline(y2,x1,x2,-1);
		xx[cnt]=x2;
	}
	sort(xx+1,xx+cnt+1);
	sort(line+1,line+cnt+1,cmp);
	ll num=unique(xx+1,xx+cnt+1)-(xx+1);
	for(ll i=1;i<=cnt;i++)
	{
		ll l,r;
		ans=ans+length[1]*(line[i].y-line[i-1].y);
		l=lower_bound(xx+1,xx+num+1,line[i].left_x)-xx;
		r=lower_bound(xx+1,xx+num+1,line[i].right_x)-xx;
		update(l,r,line[i].inout,1,1,num);
	}
	cout<<ans;
	return 0; 
}
