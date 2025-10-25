#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
map<ll,ll> v;
ll a[10010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	n=2021041820210418;
	for(ll i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			cnt++;
			while(n%i==0)
			{				
				n=n/i;		
				a[cnt]=i;			
				v[i]++;
				
			}
		}
		if(n==1) break;
		
	}
	for(ll i=1;i<=cnt;i++)
	{
		cout<<a[i]<<"   " <<v[a[i]]<<"\n";
    }
	cout<<cnt;
	return 0;
}
