#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll nex[N],n,ans;
string p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>p;
	for(ll i=1;i<=n-1;i++)
	{
		ll j=nex[i];
		while(j&&p[j]!=p[i]) j=nex[j];
		if(p[j]==p[i]) nex[i+1]=j+1;
		else nex[i+1]=0;
	} 
	for(ll i=2;i<=n;i++)
	{
		ll j=i;
		while(nex[j]) j=nex[j];
		if(nex[i]) nex[i]=j;
		ans=ans+i-j;
	}
    cout<<ans;
	return 0;
}
