#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=300;
struct country{
	ll id,num;
};
country b[N];
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=(1<<n);i++) 
	{
		cin>>b[i].num;
		b[i].id=i;
	}
	for(ll i=n-1;i>=1;i--)
	{
		for(ll j=1;j<=(1<<i);j++)
		{
			if(b[j*2-1].num>b[j*2].num) 
			{
				b[j].num=b[j*2-1].num;
				b[j].id=b[j*2-1].id;
			}
			else
			{
				b[j].num=b[j*2].num;
				b[j].id=b[j*2].id;
			}
		}
	}
	if(b[1].num>b[2].num) cout<<b[2].id;
	else cout<<b[1].id;
	return 0;
}
