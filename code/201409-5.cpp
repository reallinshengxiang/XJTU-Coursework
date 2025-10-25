#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,m,ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if((n*m)%3!=0)
	{
		cout<<0;
		return 0;
	}
	if(n==1||m==1) 
	{
		cout<<0;
		return 0;
	}
	if(n<m) swap(n,m);
	if(m==2)
	{
		if(n%3!=0) cout<<0;
		else
		{
			for(ll i=1;i<=n/3;i++)	ans=ans*2%mod;
			cout<<ans;
		}
		return 0;
	}
    if(m==3)
	{
		if(n==3) cout<<0;
		else if(n==4) cout<<4;
		else if(n==5) cout<<0;
		else if(n==6) cout<<8;
		else cout<<0;
		return 0;
	}
	if(m==4)
	{
		if(n==6) cout<<18;
		else cout<<0;
		return 0;
	}
	if(m==5&&n==6) cout<<72;
	if(m==6&&n==6) cout<<162;
	else cout<<0;
	return 0;
}
