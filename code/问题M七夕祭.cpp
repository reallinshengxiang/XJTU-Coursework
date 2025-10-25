#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,a[100010],b[100010],s[100010],x,y,ans,ans1,ans2,ave,xx,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>t;
	k=t;
	while(k--)
	{
		cin>>x>>y;
		a[x]++;
		b[y]++;		
	}
	if((t%n)&&(t%m))
	{
		cout<<"impossible";
		return 0;
	}
	if(t%n==0&&t%m!=0)
	{
		ave=t/n;
		for(ll i=1;i<=n;i++) 
		{
			a[i]=a[i]-ave;
			s[i]=s[i-1]+a[i];
		}
		sort(s+1,s+n+1);
		xx=s[(n+1)/2];
		for(ll i=1;i<=n;i++) ans=ans+abs(s[i]-xx);
		cout<<"row "<<ans;
	}
	else if(t%n!=0&&t%m==0)
	{
		ave=t/m;
		for(ll i=1;i<=m;i++) 
		{
			b[i]=b[i]-ave;
			s[i]=s[i-1]+b[i];
		}
		sort(s+1,s+m+1);
		xx=s[(m+1)/2];
		for(ll i=1;i<=m;i++) ans=ans+abs(s[i]-xx);
		cout<<"column "<<ans;
	}
	else
	{
		ave=t/n;
		for(ll i=1;i<=n;i++) 
		{
			a[i]=a[i]-ave;
			s[i]=s[i-1]+a[i];
		}
		sort(s+1,s+n+1);
		xx=s[(n+1)/2];
		for(ll i=1;i<=n;i++) ans1=ans1+abs(s[i]-xx);
		memset(s,0,sizeof(s));
		ave=t/m;
		for(ll i=1;i<=m;i++) 
		{
			b[i]=b[i]-ave;
			s[i]=s[i-1]+b[i];
		}
		sort(s+1,s+m+1);
		xx=s[(m+1)/2];
		for(ll i=1;i<=m;i++) ans2=ans2+abs(s[i]-xx);
		cout<<"both "<<ans1+ans2;
	}
	return 0;
}
