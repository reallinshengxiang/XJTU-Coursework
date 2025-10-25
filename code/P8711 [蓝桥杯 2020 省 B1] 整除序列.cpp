#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n!=0)
	{
		cout<<n<<" ";
		n=n/2;
	}
	return 0;
}
