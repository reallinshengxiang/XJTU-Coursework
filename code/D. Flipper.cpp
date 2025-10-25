#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e3+10;
ll T,st,n,p[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>p[i];
		if(n==1) 
		{
			cout<<"1\n";
			continue;
		}
		if(p[1]==n)
		{
			for(ll i=1;i<=n;i++) 
			{
				if(p[i]==n-1)
				{
					st=i;
					break;
				}
			}
	    }
		else
		{
			for(ll i=1;i<=n;i++)
			{
				if(p[i]==n)
				{
					st=i;
					break;
				}
			}
		}
		if(st==n&&p[1]>=p[st-1])
		{
			cout<<p[st]<<" ";
			for(ll i=1;i<=st-1;i++) cout<<p[i]<<" ";
			cout<<"\n";
			continue;
		}
		for(ll i=st;i<=n;i++) cout<<p[i]<<" ";
		st--;
		cout<<p[st]<<" ";	
		st--;	
		while(st>=2&&p[st]>=p[1]) 
		{			
			cout<<p[st]<<" ";
			st--;
		}
		for(ll i=1;i<=st;i++) cout<<p[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
