#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10,inf=1e9+10;
ll a[N],q[N],s[N],cnt,n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	q[0]=inf;
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=cnt,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[i]>=q[mid]) l=mid+1;
			else r=mid-1;
		}
		l--;
		if(q[l]!=a[i])
		{
			cnt++;
			s[cnt]=1;
			q[cnt]=a[i]+1;
		}
		else
		{
			s[l]++;
			q[l]++;
		}
	}
	ans=n;
	for(ll i=1;i<=cnt;i++) ans=min(ans,s[i]);
	cout<<ans;
	return 0; 
} 
