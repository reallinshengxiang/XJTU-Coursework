#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define ll long long
ll maxa,maxb,x,k1,k2,k,t,cnt;
double y,a[22],b[22],c[22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k1;
	while(k1--)
	{
		cin>>x>>y;
		a[x]=y;
		maxa=max(maxa,x);
	}
	cin>>k2;
	while(k2--)
	{
		cin>>x>>y;
		b[x]=y;
		maxb=max(maxb,x);
	}
	k=max(maxa,maxb);
	for(ll i=0;i<=k;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]!=0) cnt++;
	}
	cout<<cnt<<" ";
	t=0;
	while(c[t]==0) t++;
	for(ll i=k;i>=t+1;i--)
	{
		if(c[i]!=0) cout<<i<<" "<<setprecision(1)<<fixed<<c[i]<<" ";
	}
	cout<<t<<" "<<setprecision(1)<<fixed<<c[t];
	return 0;
}
