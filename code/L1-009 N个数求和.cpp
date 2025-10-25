#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,b,ansa,ansb;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	scanf("%lld/%lld",&ansa,&ansb);
	for(ll i=2;i<=n;i++)
	{
		scanf("%lld/%lld",&a,&b);
		ansa=ansa*b+ansb*a;
		ansb=ansb*b;		
		ll aa=abs(ansa);
		ll bb=abs(ansb);
		ll xx=__gcd(aa,bb);
		aa=aa/xx;
		bb=bb/xx;
		if(ansa<0) ansa=-aa;
		else ansa=aa; 
		ansb=bb;
	}
	if(ansb==1) cout<<ansa;
	else if(ansb<ansa) cout<<ansa/ansb<<" "<<ansa%ansb<<"/"<<ansb;
	else cout<<ansa<<"/"<<ansb;
	return 0;
}
