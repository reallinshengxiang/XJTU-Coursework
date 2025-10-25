#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
const ll mod=998244353;
ll tree[N<<2],len,t,m,p,sum,n,a[N],d,f[N],yy,vis[N],minn,maxx;
ll ls(ll p){return p<<1;}
ll rs(ll p){return p<<1|1;}
void push_up(ll p)
{	
    tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
	if(vis[ls(p)]) tree[p]=(tree[p]+1)%mod;
	if(vis[rs(p)]) tree[p]=(tree[p]+1)%mod;
}
void update(ll p,ll pl,ll pr,ll x,ll d)
{
    if(pl==x&&pr==x)
    {
        tree[p]=(tree[p]+d)%mod;
        return;
    }
    ll mid=(pl+pr)>>1;
    if(x<=mid) update(ls(p),pl,mid,x,d);
    else update(rs(p),mid+1,pr,x,d);
    push_up(p);
}
ll query(ll l,ll r,ll p,ll pl,ll pr)
{
    if(pl>=l&&pr<=r)  return tree[p];
    ll mid=(pl+pr)>>1;
    ll ans=0;
    if(l<=mid) ans=(ans+query(l,r,ls(p),pl,mid))%mod;
    if(r>mid)  ans=(ans+query(l,r,rs(p),mid+1,pr))%mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d;
    for(ll i=1;i<=n;i++)
    {
    	ll x;
    	cin>>x;
    	minn=max((ll)1,x-d);
    	maxx=x+d; 	
		yy=(query(minn,maxx,1,1,N))%mod;
		update(1,1,N,x,yy);
		f[i]=yy;
		vis[x]=1;
		sum=sum+f[i];
	}
	cout<<(sum+mod-n)%mod;
    return 0;
}

