#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
ll tag[N<<4],tree[N<<4],xx[N],n,cnt;
struct scaneline{
	ll y,right_x,left_x,inout; 
};
scaneline line[N];
bool cmp(scaneline a,scaneline b)
{
	if(a.y<b.y) return 1;
	return 0;
}
void push_up(ll p,ll pl,ll pr)
{
	if(tag[p]) tree[p]=xx[pr]-xx[pl];
	else if(pl+1==pr) tree[p]=0;
	else tree[p]=tree[ls(p)]+tree[rs(p)];
}
void update(ll l,ll r,ll inout,ll p,ll pl,ll pr)
{
	if(l<=pl&&r>=pr)
	{
		tag[p]=tag[p]+inout;
		push_up(p,pl,pr);
		return;
	}
	if(pl+1==pr) return;
	ll mid=(pl+pr)>>1;
	if(l<=mid) update(l,r,inout,ls(p),pl,mid);
	if(r>mid) update(l,r,inout,rs(p),mid,pr);
	push_up(p,pl,pr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		cnt++;
		line[cnt]=(scaneline){y1,x2,x1,1};
		xx[cnt]=x1;
		cnt++;
		line[cnt]=(scaneline){y2,x2,x1,-1};
		xx[cnt]=x2;
	}
	sort(xx+1,xx+cnt+1);
	sort(line+1,line+cnt+1,cmp);
	ll num=unique(xx+1,xx+cnt+1)-(xx+1);
	ll ans=0;
	for(ll i=1;i<=cnt;i++)
	{
		ll l,r;
		ans=ans+tree[1]*(line[i].y-line[i-1].y);
	    l=lower_bound(xx+1,xx+num+1,line[i].left_x)-xx;
	    r=lower_bound(xx+1,xx+num+1,line[i].right_x)-xx;
	    update(l,r,line[i].inout,1,1,num);
	}
	cout<<ans;
	return 0;
}
