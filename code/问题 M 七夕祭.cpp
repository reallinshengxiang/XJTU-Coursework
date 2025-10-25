#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[100010],y[100010],a[100010],s[100010],ans,t,n,m,xx,ans1,ans2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>t;
	for(ll i=1;i<=t;i++) cin>>x[i]>>y[i];
	if((t%n)&&(t%m))
	{
		cout<<"impossible";
		return 0;
	}
	else if(t%n==0&&t%m!=0)
	{
		cout<<"row ";
		for(ll i=1;i<=t;i++) a[x[i]]++;
		ans=t/n;
		for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i]-ans;
		sort(s+1,s+n+1);
		xx=s[(n+1)/2];
		ans=0;
		for(ll i=1;i<=n;i++) ans=ans+abs(s[i]-xx);
		cout<<ans;
	}
	else if(t%n!=0&&t%m==0)
	{
		cout<<"column ";
		for(ll i=1;i<=t;i++) a[y[i]]++;
		ans=t/m;
		for(ll i=1;i<=m;i++) s[i]=s[i-1]+a[i]-ans;
		sort(s+1,s+m+1);
		xx=s[(m+1)/2];
		ans=0;
		for(ll i=1;i<=m;i++) ans=ans+abs(s[i]-xx);
		cout<<ans;
	}
	else
	{
		cout<<"both ";
		for(ll i=1;i<=t;i++) a[x[i]]++;
		ans=t/n;
		for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i]-ans;
		sort(s+1,s+n+1);
		xx=s[(n+1)/2];
		ans1=0;
		for(ll i=1;i<=n;i++) ans1=ans1+abs(s[i]-xx);
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		for(ll i=1;i<=t;i++) a[y[i]]++;
		ans2=t/m;
		for(ll i=1;i<=m;i++) s[i]=s[i-1]+a[i]-ans;
		sort(s+1,s+m+1);
		xx=s[(m+1)/2];
		ans2=0;
		for(ll i=1;i<=m;i++) ans2=ans2+abs(s[i]-xx);
		cout<<ans1+ans2;
	}
	return 0;
}
