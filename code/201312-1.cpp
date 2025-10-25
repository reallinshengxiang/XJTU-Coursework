#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll n,a[N],b[N],maxnum,maxx,cnt;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		if(!mp[a[i]])
		{
			mp[a[i]]=1;
			cnt++;
		}
	    b[cnt]++;
	    if(b[cnt]>maxnum)
	    {
	    	maxnum=b[cnt];
	    	maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}
