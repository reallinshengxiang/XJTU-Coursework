#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,k,ans,a,b,ans1,ans2;
double kk,aa; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		if(i*i*i>k) break;
		aa=k/(i*i);
		b=aa;
		b=min(b,n);
		ans1=(i*i*(i+b)*(b-i+1)/2*3)%mod;
		ans2=(i*i*i*2)%mod;
	    ans=(ans+(ans1+mod-ans2)%mod)%mod;
		for(ll j=i+1;j<=n;j++)
		{
			if(i*j*j>k) break;
			aa=k/(i*j);
			b=aa;
			b=min(b,n);
			ans1=i*j*(j+b)*(b-j+1)*3%mod;
			ans2=(i*j*j*3)%mod;
			ans=(ans+(ans1-ans2+mod)%mod)%mod;
		}	    
	}
	cout<<ans;
	return 0;
}
