#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=510;
ll p,ans[N],pow2=1,len=500;
void mul(ll x)
{
	for(ll i=1;i<=len;i++) ans[i]=ans[i]*x;
	for(ll i=1;i<=len;i++)
	{
		ans[i+1]=ans[i+1]+ans[i]/10;
		ans[i]=ans[i]%10;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p;
	cout<<ceil(p*log10(2))<<"\n";
	for(ll i=1;i<=32;i++) pow2=pow2*2;
	ans[1]=1;
	for(ll i=1;i<=p/32;i++) mul(pow2);
	for(ll i=1;i<=p-p/32*32;i++) mul(2);
	for(ll i=500;i>=1;i--) 
	{
		if(i==1) ans[i]--;
		cout<<ans[i];
		if(i%50==1) cout<<"\n";
	}
	return 0;
}
