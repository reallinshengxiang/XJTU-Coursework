#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2;i++)
	{
		a=a+4;
		for(ll j=1;j<=5;j++)
		{
			for(ll k=1;k<=6;k++)
			{
				a=a+5;
			}
			a=a+7;
		}
		a=a+8;
	}
	a=a+9;
	cout<<a;
	return 0;
}
