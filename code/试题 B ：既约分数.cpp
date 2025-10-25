#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll x,y;
	bool operator <(const node &a) const
	{
		if(x>a.x) return 1;
		else if(x==a.x&&y>a.y) return 1;
		return 0;
	} 
};
node p;
map<node,ll> mp;
ll ans,xx,yy,z;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=2020;i++)
	{
		for(ll j=1;j<=2020;j++)
		{
			xx=i;
			yy=j;
			z=__gcd(xx,yy);
			p.x=xx/z;
			p.y=yy/z;
		//	cout<<xx<<" "<<yy<<"                 ";
			if(!mp[p])
			{
		//		cout<<xx<<"  "<<yy<<"    "<<p.x<<"  "<<p.y<<"\n";
				ans++;
				mp[p]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
