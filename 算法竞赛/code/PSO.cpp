#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
double n; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<fixed<<setprecision(9)<<2.0*(n-1)/n<<" "<<2.0<<"\n";
	}
	return 0;
}
