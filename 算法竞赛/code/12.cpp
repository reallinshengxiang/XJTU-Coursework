#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ll ans;
ld l;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l;
	while(l>1.00000000)
	{
		l=l/2;
		ans++;
	}
	cout<<ans;
	return 0;
}
