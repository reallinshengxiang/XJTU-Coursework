#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,x,num[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum1=0,sum2=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		num[x]++;
	}
	for(ll i=1;i<=100000;i++)
	{
		if(num[i]==1) sum1++;
		else if(num[i]>2) sum2=sum2+num[i]-2;
	}
	if(sum1==0&&sum2==0) cout<<0;
	if(sum1>sum2) cout<<(sum1-sum2)/2+sum2;
	else cout<<sum2;
	return 0;
}
