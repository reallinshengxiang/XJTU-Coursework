#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],c[N],b[N],n,flag,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	b[1]=200;
	for(ll i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) b[i]=b[i-1]+100;
		else if(a[i]==a[i-1]) b[i]=b[i-1]; 
		else b[i]=200;
	}
	c[n]=200;
	for(ll i=n-1;i>=1;i--)
	{
		if(a[i]>a[i+1]) c[i]=c[i+1]+100;
		else if(a[i]==a[i+1]) c[i]=c[i+1]; 
		else c[i]=200;
	}
	for(ll i=1;i<=n;i++) ans=ans+max(b[i],c[i]);
	//for(ll i=1;i<=n;i++) cout<<b[i]<<" ";
	//cout<<"\n";
	//for(ll i=1;i<=n;i++) cout<<c[i]<<" ";
	//cout<<"\n";
	cout<<ans;
	return 0;
 } 
