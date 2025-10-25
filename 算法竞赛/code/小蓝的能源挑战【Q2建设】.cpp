#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,x,y,z;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		if(x<y) cout<<"BRIDGE\n";
		else if(x>y) cout<<"YI\n";
		else if(x==y) cout<<"ANY\n";
	}
	return 0;
} 
