#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x=2021041820210418,cnt,a[210],ans;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	for(ll i=1;i<=sqrt(x);i++)
	{
		if(x%i==0) a[++cnt]=i,a[++cnt]=x/i;
	}
	cout<<cnt<<"\n";
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=1;j<=cnt;j++)
		{
			for(ll k=1;k<=cnt;k++) 
			{
				if(a[i]*a[j]*a[k]==x) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
