#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
double sum,a[10],ans,b[10];
ll n;
bool cmp(double x,double y)
{
	if(x>y) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],sum=sum+a[i];
	for(ll i=1;i<=n;i++) a[i]=a[i]/sum;
	sort(a+1,a+n+1,cmp);	
	//for(ll i=1;i<=n;i++) cout<<fixed<<setprecision(4)<<a[i]<<" ";
	//cout<<"\n";
	if(n%2)
	{
		for(ll i=1;i<=n;i=i+2)	b[n/2+1+i/2]=a[i];
	    for(ll i=2;i<=n;i=i+2)	b[n/2+1-i/2]=a[i];
	}
	else
	{
		for(ll i=1;i<=n;i=i+2) b[n/2+1+i/2]=a[i];
		for(ll i=2;i<=n;i=i+2) b[n/2+1-i/2]=a[i];
	}
    //for(ll i=1;i<=n;i++) cout<<fixed<<setprecision(4)<<b[i]<<" ";
	//cout<<"\n";
	for(ll i=1;i<=n-1;i++) 
	{
		for(ll j=i+1;j<=n;j++)  ans=ans+abs(j-i)*b[j]*b[i];
	}
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
