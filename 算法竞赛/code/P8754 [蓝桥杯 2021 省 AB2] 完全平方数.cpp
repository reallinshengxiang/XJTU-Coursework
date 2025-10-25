#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num,n,x=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=2;i<=sqrt(n);i++)
	{
		num=0;
		while(n%i==0)
		{
			num++;
			n=n/i;
		}
		if(num%2) x=x*i;
	}
	x=x*n;
	cout<<x;
	return 0;
}
