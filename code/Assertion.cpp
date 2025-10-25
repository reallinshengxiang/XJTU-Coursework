#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,m,d,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>d;
		x=m/n;
		if(m%n) x++;
		if(d<=x) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
