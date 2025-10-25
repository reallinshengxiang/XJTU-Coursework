#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n%6==0) cout<<"Roy wins!\n";
		else cout<<"October wins!\n";
	}
	return 0;
}
