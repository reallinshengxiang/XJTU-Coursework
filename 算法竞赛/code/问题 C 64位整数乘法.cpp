#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  a,b,p,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>p;
	while(b)
	{
		if(b&1) ans=(ans+a)%p;
		a=(a*2)%p;
		b>>=1;
	}
	cout<<ans;
	return 0;
}
