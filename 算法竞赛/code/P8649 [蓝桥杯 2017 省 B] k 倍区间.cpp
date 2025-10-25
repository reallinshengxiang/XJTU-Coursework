#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,k,num[N],sum,x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	num[0]=1;
	for(ll i=1;i<=n;i++) 
	{
		cin>>x;
		sum=(sum+x%k)%k;
		num[sum]++;
	}
	for(ll i=0;i<=k-1;i++) ans=ans+(num[i])*(num[i]-1)/2;
	cout<<ans;
	return 0; 
}
