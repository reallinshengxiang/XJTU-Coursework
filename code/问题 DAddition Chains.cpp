#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flag,a[10010],len,n;
void dfs(ll step)
{
	if(step>len) return;
	if(step==len&&a[step]==n)
	{
		for(ll i=1;i<=step;i++) cout<<a[i]<<" ";
		cout<<"\n";
		flag=1;
		return; 
	}
	for(ll i=step;i>=1;i--)
	{
		for(ll j=step;j>=i;j--)
		{
			if(a[i]+a[j]>a[step]&&a[i]+a[j]<=n)
			{
				a[step+1]=a[i]+a[j];
				ll x=a[step+1];
				for(ll k=step+2;k<=len;k++) x=x*2;
				if(x<n) continue;
				dfs(step+1);
				if(flag) return;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n)
	{
		if(n==0) break;
		len=1;
		memset(a,0,sizeof(a));
		a[1]=1;
		a[2]=2;
		ll x=1;
		while(x<n)
		{
			x=x*2;
			len++;
		}
		flag=0;
		while(!flag)
		{
			dfs(1);
			len++;
		}
	}
	return 0;
}
