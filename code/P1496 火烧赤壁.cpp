#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
ll l[N],r[N],a[2*N],n,num,cnt,d[2*N],sum[2*N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		cnt++;
		a[cnt]=l[i];
		cnt++;
		a[cnt]=r[i];
	}
	sort(a+1,a+cnt+1);
	num=unique(a+1,a+cnt+1)-(a+1);
	for(ll i=1;i<=n;i++)
	{
		l[i]=lower_bound(a+1,a+num+1,l[i])-a;
		r[i]=lower_bound(a+1,a+num+1,r[i])-a;
	}
	for(ll i=1;i<=n;i++)
	{
		d[l[i]]++;
		d[r[i]]--;
	}
	for(ll i=1;i<=num;i++)
	{
		sum[i]=d[i]+sum[i-1];
		if(sum[i]) ans=ans+a[i+1]-a[i];
	}
	cout<<ans;
	return 0;
}
