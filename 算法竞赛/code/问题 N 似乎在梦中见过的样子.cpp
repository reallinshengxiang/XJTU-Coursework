#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll nex[15050],n,ans,k;
string p,s;
void kmp(ll x)
{
	n=p.size();
	for(ll i=1;i<=n-1;i++)
	{
		ll j=nex[i];
		while(j&&p[i]!=p[j]) j=nex[j];
		if(p[i]==p[j]) nex[i+1]=j+1;
		else nex[i+1]=0;
	}
	ll j=0;
	for(ll i=0;i<=n-1;i++)
	{
		while(j&&p[i]!=p[j]) j=nex[j];
		if(p[i]==p[j]) j++;
		while(j&&j*2>i) j=nex[j];
		if(j>=k) ans++; 
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>k;
	for(ll i=0;i<s.size();i++)
	{
		p=s.substr(i,s.size()-i+1);
		kmp(i);
	}
	cout<<ans;
	return 0;
}
