#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct shu{
	ll a,b;
};
shu num[100010];
ll x,y,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>y;
	if(y%x!=0)
	{
		cout<<"0\n";
		return 0;
	}
	y=y/x;
	for(ll i=1;i<=sqrt(y);i++)
	{
		if(y%i==0&&i*i!=y&&__gcd(i,y/i)==1)
		{
			cnt++;
			num[cnt].a=i;
			num[cnt].b=y/i;
			cnt++;
			num[cnt].a=y/i;
			num[cnt].b=i;
		}
		else if(y%i==0&&i*i==y&&__gcd(i,y/i)==1)
		{
			cnt++;
			num[cnt].a=i;
			num[cnt].b=y/i;
		}
	}
	cout<<cnt<<"\n";
	for(ll i=1;i<=cnt;i++) cout<<num[i].a*x<<" "<<num[i].b*x<<"\n";
}
