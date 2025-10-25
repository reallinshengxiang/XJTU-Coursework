#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll pp=131;
ll h[1000010],p[1000010];
string s;
ll n,len;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	cin>>n;
	len=s.size();
	s=" "+s;
	p[0]=1;
	for(ll i=1;i<=len;i++)
	{
		h[i]=h[i-1]*pp+(s[i]-'a'+1);
		p[i]=p[i-1]*pp;
	}
	for(ll i=1;i<=n;i++)
	{
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		if((h[y1]-h[x1-1]*p[y1-x1+1])==(h[y2]-h[x2-1]*p[y2-x2+1])) cout<<"Yes\n";
		else cout<<"No\n"; 
	}
	return 0;
}
