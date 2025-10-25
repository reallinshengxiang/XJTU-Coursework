#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[11],x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=0;i<=9;i++) num[i]=2021;
	for(ll i=1;;i++)
	{
		x=i;
		while(x!=0)
		{
			num[x%10]--;
			if(num[x%10]<0) 
			{
				cout<<i-1;
				return 0;
			}
			x=x/10;
		}
	}
	return 0;
}
