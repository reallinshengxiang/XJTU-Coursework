#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15e4+10;
ll f[N],n,k,x,y,opt,ans;
ll find_set(ll x)
{
	if(f[x]!=x) f[x]=find_set(f[x]);
	return f[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=3*n;i++) f[i]=i;
	for(ll i=1;i<=k;i++)
	{
		cin>>opt>>x>>y;
		if(x>n||y>n)
		{
			ans++;
			continue;
		}
		if(opt==1)
		{
			if(find_set(x+n)==find_set(y)||find_set(x)==find_set(y+n)) ans++;
			else
		    {
			   f[find_set(x)]=find_set(y);
			   f[find_set(x+n)]=find_set(y+n);
			   f[find_set(x+2*n)]=find_set(y+2*n);
		    }
		}
		else if(opt==2)
		{
			if(find_set(x)==find_set(y)||find_set(x)==find_set(y+n)) ans++;
			else
			{
				f[find_set(x+n)]=find_set(y);
				f[find_set(x+2*n)]=find_set(y+n);
				f[find_set(x)]=find_set(y+2*n);
			}
		}		
	}
	cout<<ans;
	return 0;
}
