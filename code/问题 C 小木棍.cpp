#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxx=-100,minn=100,t[100],x,sum,n;
void dfs(ll res,ll sum,ll tt,ll x)
{
	if(res==0) 
	{
		cout<<tt;
		exit(0);
	}
	if(sum==tt)  
	{
		dfs(res-1,0,tt,maxx);
		return;
	}
	for(ll i=x;i>=minn;i--)
	{
		if(t[i]&&i+sum<=tt)
		{
			t[i]--;
			dfs(res,sum+i,tt,i);
			t[i]++;
			if(sum==0||sum+i==tt) break;
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		sum=sum+x;
		t[x]++;
		maxx=max(maxx,x);
		minn=min(minn,x);
	}
	x=sum/2;
	for(ll i=maxx;i<=x;i++)
	{
		if(sum%i==0)	dfs(sum/i,0,i,maxx);
	}
	cout<<sum;
	return 0;
}
