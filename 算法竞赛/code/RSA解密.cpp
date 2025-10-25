#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int128 __int128
int128 n=1001733993063167141,d=212353,p,q,mm,c;
ll e;
ll fast_pow(int128 x,int128 n,int128 mod)
{
	ll ans=1;
	while(n)
	{
		if(n&1) ans=(ans*(x%mod))%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return ans;
} 
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	p=891234941;
	q=1123984201;
	e=823816093931522017;
	c=20190324;
	cout<<fast_pow(c,e,n);
	return 0;
}
