#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Inf=1e9;
ll n,m,ans=Inf,rr[30],hh[30],minv[30],mins[30];
void dfs(ll step,ll v,ll s)
{
	if(v+minv[step]>n) return;
	if(s+mins[step]>=ans||s+2*(n-v)/rr[step+1]>=ans) return;
	if(!step)
	{
		if(n==v) ans=s;
		return;
	}
	for(ll r=min((ll)sqrt(n-v),rr[step+1]-1);r>=step;r--)
	{
		for(ll h=min((n-v)/r/r,hh[step+1]-1);h>=step;h--)
        { 
            ll t=0;
            if(step==m)  t=r*r;
            rr[step]=r;
			hh[step]=h;
            dfs(step-1,v+r*r*h,s+2*r*h+t);
        }
	}
        
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
    {
        minv[i]=minv[i-1]+i*i*i;
        mins[i]=mins[i-1]+2*i*i;
    }
    rr[m+1]=hh[m+1]=Inf;
    dfs(m,0,0);
    cout<<ans;
	return 0;
}
