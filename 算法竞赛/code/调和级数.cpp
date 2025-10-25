#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
ld sum=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;;i++)
	{
		sum=sum+1.0/i;
		if(sum>=12.0) 
		{
			cout<<i<<"\n";
			break;
		}
	}
	return 0;
}
