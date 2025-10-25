#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(ll x1,ll y1,ll a,ll b,ll k)
{
	if(k==0) return;
	ll len=1<<(k-1);
	if(k==1) len=1;
	ll midx=x1+len,midy=y1+len;
	if(a<midx&&b<midy)
	{
		cout<<midx<<" "<<midy<<" "<<1<<"\n";
		solve(x1,y1,a,b,k-1);
		solve(x1,midy,midx-1,midy,k-1);
		solve(midx,y1,midx,midy-1,k-1);
		solve(midx,midy,midx,midy,k-1);
	} 
	else if(a<midx&&b>=midy)
	{
		cout<<midx<<" "<<midy-1<<" "<<2<<"\n";
		solve(x1,y1,midx-1,midy-1,k-1);
		solve(x1,midy,a,b,k-1);
		solve(midx,y1,midx,midy-1,k-1);
		solve(midx,midy,midx,midy,k-1);
	}
	else if(a>=midx&&b<midy)
	{
		cout<<midx-1<<" "<<midy<<" "<<3<<"\n";
		solve(x1,y1,midx-1,midy-1,k-1);
		solve(x1,midy,midx-1,midy,k-1);
		solve(midx,y1,a,b,k-1);
		solve(midx,midy,midx,midy,k-1);
	} 
	else if(a>=midx&&b>=midy)
	{
		cout<<midx-1<<" "<<midy-1<<" "<<4<<"\n";
		solve(x1,y1,midx-1,midy-1,k-1);
		solve(x1,midy,midx-1,midy,k-1);
		solve(midx,y1,midx,midy-1,k-1);
		solve(midx,midy,a,b,k-1);
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k,x,y;
	cin>>k>>x>>y;
	solve(1,1,x,y,k);
	return 0;
}
