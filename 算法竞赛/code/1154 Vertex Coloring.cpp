#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+10;
ll x[N],y[N],n,m,a[N],k;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>x[i]>>y[i];
	cin>>k;
	for(ll i=1;i<=k;i++)
	{
		ll flag=0,cnt=0;
		mp.clear();
		for(ll j=1;j<=n;j++) 
		{
			cin>>a[j];
			if(!mp[a[j]]) mp[a[j]]=1,cnt++;
		}
		//for(ll j=1;j<=n;j++) cout<<a[j]<<" ";
		//cout<<"\n";
		for(ll j=1;j<=m;j++)
		{
			if(a[x[j]+1]==a[y[j]+1])
			{
				flag=1;
				break;
			}
		}
		if(flag) cout<<"No\n";
		else cout<<cnt<<"-coloring\n";
	}
	return 0;
}
