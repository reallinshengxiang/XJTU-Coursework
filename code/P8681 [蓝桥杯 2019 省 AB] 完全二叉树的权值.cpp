#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll sum[N],ansi,maxx,x,pos,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		sum[i]=sum[i-1]+x;
	}
	pos=1;
	for(ll i=1;;i++)
	{
		pos=pos*2;
		x=sum[min(pos-1,n)]-sum[pos/2-1];
		if(i==1) maxx=x;
		if(x>maxx)
		{
			maxx=x;
			ansi=i;
		}
		if(pos-1>=n) break;
	}
	cout<<ansi;
	return 0;
}
