#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k;
	n=1;
	while(k>=n)
	{
		ans=ans+n*n;
		k=k-n;
		n++;		
	}
	ans=ans+k*n;
	cout<<ans;
	return 0;
}
