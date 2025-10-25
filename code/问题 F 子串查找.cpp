#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,p;
ll slen,plen,ans,nex[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	getline(cin,p);
	slen=s.size();
	plen=p.size();
	nex[0]=nex[1]=0;
	for(ll i=1;i<=plen-1;i++)
	{
		ll j=nex[i];
		while(j&&p[i]!=p[j]) j=nex[j];
		if(p[i]==p[j]) nex[i+1]=j+1;
		else nex[i+1]=0; 
	}
	ll j=0;
	for(ll i=0;i<=slen-1;i++)
	{
		while(j&&s[i]!=p[j]) j=nex[j];
		if(s[i]==p[j]) j++;
		if(j==plen)	ans++;
	}
	cout<<ans;
	return 0;
}
