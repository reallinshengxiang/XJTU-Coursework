#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxv=1e9+10,minv,n,a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		maxv=min(maxv,a/b);
		minv=max(minv,a/(b+1)+1);
	}
	cout<<minv<<" "<<maxv;
	return 0;
 } 
