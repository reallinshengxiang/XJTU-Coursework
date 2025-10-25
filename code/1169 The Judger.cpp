#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=12,M=1e5+10;
unordered_map<ll,ll> mp;
ll flag[N],b[N][M],a[M],n,m,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a[1]>>a[2]>>n>>m;
	cnt=2;
	mp[a[1]]=1;
	mp[a[2]]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>b[i][j];
	}
	for(ll round=1;round<=m;round++)
	{
		for(ll id=1;id<=n;id++)
		{
			if(flag[id]) continue;
			if(mp[b[id][round]]) 
			{
				flag[id]=1;
				cout<<"Round #"<<round<<": "<<id<<" is out.\n";
			}
			else
			{
				ll f=0;
				for(ll i=1;i<=cnt;i++)
				{
					if(mp[b[id][round]+a[i]])
					{
						f=1;
						break;
					}
				}
				if(!f)
				{
					flag[id]=1;
					cout<<"Round #"<<round<<": "<<id<<" is out.\n";
				}
				if(!flag[id])
				{
					cnt++;
					a[cnt]=b[id][round];
					mp[b[id][round]]=1;
				}
			}
		}
	}
	ll f=0;
	for(ll i=1;i<=n;i++) 
	{
		if(!flag[i])  f++;
	}
	if(!f) cout<<"No winner.";
	else
	{
		cout<<"Winner(s): ";
		//cout<<"\n"<<f<<"\n";
		for(ll i=1;i<=n;i++) 
		{
			if(!flag[i]) 
			{
				cout<<i;
				f--;
				if(f) cout<<" ";	
			}
			
		}	
	} 
	return 0;
}
