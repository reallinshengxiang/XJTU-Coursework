#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[1100],v[1100],a,b,x;
ll minn(ll a,ll b)
{
	ll xx=b/a;
	if(xx*a>=b) return xx;
	else return xx+1;
}
bool check(ll xx)
{
	for(ll i=xx;i>=0;i--)
	{
		if(v[i]!=ans[i]) 
		{
			if((ans[i]==-1)||(v[i]<ans[i])) return 1;
			else return 0;
		}
	}
	return 0;
}
ll dfs(ll d,ll from,ll aa, ll bb)
{
	if(d==x)
	{
		if(bb%aa)  return 0;
		v[d]=bb/aa; 
		if(check(d)) memcpy(ans,v,sizeof(ll)*(d+1));
		return 1;
	}
	ll flag=0;
	from=max(from,minn(aa, bb));
	ll i=from;
	while(1)
	{
		if (bb*(x+1-d)<=i*aa)   break;
		v[d]=i;
		ll b2=bb*i;
		ll a2=aa*i-bb;
		ll g=__gcd(a2, b2);
		if (dfs(d+1,i+1,a2/g,b2/g))  flag=1;
		i++;
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	x=1;
	while(1)
	{
		memset(ans,-1,sizeof(ans));
		if(dfs(0,minn(a,b),a,b)) break;
		x++;
	}
	for(ll i=0;i<=x;i++) cout<<ans[i]<<" ";
	return 0;
}
