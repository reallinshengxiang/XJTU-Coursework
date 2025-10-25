#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
ll n,r,k,x[N],y[N],m,b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>r>>k;
	for(ll i=1;i<=r;i++)  cin>>x[i]>>y[i];
	cin>>m;
	while(m--)
	{
		unordered_map<ll,ll> mp;
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>b[i];
			if(mp[b[i]]!=1) cnt++,mp[b[i]]=1;
	    }
	    if(cnt<k) cout<<"Error: Too few species.\n";
	    else if(cnt>k) cout<<"Error: Too many species.\n";
	    else
	    {
	    	ll flag=0;
	    	for(ll i=1;i<=r;i++)
	    	{
	    		if(b[x[i]]==b[y[i]])
	    		{
	    			flag=1;
	    			break;
				}
			}
			if(!flag) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}
