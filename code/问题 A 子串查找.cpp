#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
ll nex[1000010],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	nex[0]=nex[1]=0;
	for(ll i=1;i<=b.size()-1;i++)
	{
		ll j=nex[i];
		while(j&&b[i]!=b[j])  j=nex[j];
		if(b[i]==b[j]) nex[i+1]=j+1;
		else nex[i+1]=0;
	}
	ll j=0;
	for(ll i=0;i<=a.size()-1;i++)
	{
		while(j&&a[i]!=b[j]) j=nex[j];
		if(a[i]==b[j]) j++;
		if(j==b.size()) ans++;
	}
	cout<<ans;
	return 0;
 } 
