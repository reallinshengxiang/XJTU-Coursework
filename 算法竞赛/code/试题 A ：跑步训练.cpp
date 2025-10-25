#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,xx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	x=10000;
	for(ll i=0;;i++)
	{
		xx=i/60;
		if(xx%2==0) x=x-10;
		else x=x+5;
		if(x<=0) 
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
