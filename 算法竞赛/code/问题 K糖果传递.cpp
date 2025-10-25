#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll a[N],ave,mid,n,s[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  
	{
		cin>>a[i];
		ave=ave+a[i];
	}
	ave=ave/n;
	s[0]=0;
	for(ll i=1;i<=n;i++) s[i]=s[i-1]+ave-a[i];
	sort(s+1,s+n+1);
	mid=n/2;
	if(n%2==1) mid++;
	for(ll i=1;i<=n;i++)  ans=ans+abs(s[i]-s[mid]);
	cout<<ans;
	return 0;
}
