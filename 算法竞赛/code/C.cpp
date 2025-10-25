#include<bits/stdc++.h>
using namespace std;
#define ll long long
double n,m;
ll t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		cout<<fixed<<setprecision(8)<<(n+m+1)*m/(m+1)<<"\n";
	}
	return 0;
}
