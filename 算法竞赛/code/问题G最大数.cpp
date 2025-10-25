#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll f[N][33];
ll cnt=0;
void add(ll x)
{
	cnt++;
	f[cnt][0]=x;
	for(ll i=1;(1<<i)<=cnt;i++)  f[cnt][i]=max(f[cnt][i-1],f[cnt-(1<<(i-1))][i-1]);
} 
ll ask(ll l)
{
	ll k=log(l)/log(2);
	return max(f[cnt][k],f[cnt-l+(1<<k)][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll m,p,x,y=0;
    char c;
	cin>>m>>p;
	while(m--)
	{
		cin>>c>>x;
		if(c=='Q')
		{
			y=ask(x);
			cout<<y<<"\n";
		}
		else add((y+x)%p);
	}
	return 0;
}
