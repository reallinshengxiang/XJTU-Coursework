#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,b,c,h;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>b>>c>>h;
		cout<<min(2*b-1,2*(c+h)+1)<<"\n";
	}
	return 0;
}
