#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>a>>b;
		if((a+b)%2) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
