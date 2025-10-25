#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5;
ll f[N],cnt,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0]=0;
	f[1]=1;
	for(ll i=2;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=1e9) 
		{
			//cout<<i<<"\n";
			cnt=i;
			break;
		}
	}
	cin>>n;
	for(ll i=1;i<=cnt-1;i++)
	{
		//cout<<f[i]<<"  "<<n<<"   "<<f[i+1]<<"\n"; 
		if(f[i]<=n&&f[i+1]>=n)
		{
			if(abs(n-f[i])<=abs(f[i+1]-n)) cout<<f[i];
			else cout<<f[i+1];
			break;
		}
	}
	return 0;
 } 
