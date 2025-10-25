#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a,ans,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a=5;
	while(n/a!=0)
	{
		ans=ans+n/a;
		a=a*5;
	}
	cout<<ans;
	return 0;
}
