#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,a[N],x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum1=0,sum2=0;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=2;i<=n;i++)
	{
		x=a[i]-a[i-1];
		if(x>0) sum1=sum1+x;
		else sum2=sum2-x;
	}
	cout<<max(sum1,sum2)<<"\n"<<abs(sum1-sum2)+1;
	return 0;
} 
