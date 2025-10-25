#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,x,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>x;
		while(x)
		{
			if(x%2) ans++;
			x=x/2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
