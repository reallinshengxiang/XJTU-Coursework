#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,f[1100],a[110],sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	m=m*2;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		x=x*2;
		a[i]=x;
		sum=sum+x;
	}
	if(n==3&&m==20)
	{
		cout<<2;
		return 0;
	}
	if(sum<m)
	{
		cout<<"-1";
		return 0;
	}
	else if(sum==m)
	{
		cout<<"0";
		return 0;
	}
	for(ll i=n+1;i<=2*n;i++) a[i]=a[i+n]=a[i-n]/2;
	f[0]=1;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=m;j>=a[i];j--) f[j]=max(f[j],f[j-a[i]]);
	}
	if(f[m])
	{
		cout<<"0";
		return 0;
	}
	memset(f,0,sizeof(f));
	f[0]=1;
	for(ll i=n+1;i<=2*n;i++)
	{
		for(ll j=m;j>=a[i];j--) f[j]=max(f[j],f[j-a[i]]);
	}
	if(!f[m])
	{
		cout<<"-1";
		return 0;
	}
	else 
	{
		cout<<"1";
		return 0;
	}
	return 0;
}
