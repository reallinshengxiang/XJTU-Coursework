#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[22],t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=0;i<=9;i++) a[i]=2021;
	for(ll i=1;i;i++)
	{
		t=i;
		while(t!=0)
		{
			if(a[t%10]) a[t%10]--;
			else
			{
				cout<<i-1<<endl;
				return 0;
			}
			t=t/10;
		}
	}
	return 0;
}
