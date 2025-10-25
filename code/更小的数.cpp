#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,s1;
ll slen,ans;
ll cmp(ll i,ll j)
{
	ll t,t1;
	t=i;
	t1=slen-1-j;
	for(ll k=0;k<=j-i;k++)
	{
		if(s[t+k]>s1[t1+k])	return 1;
		else if(s[t+k]<s1[t1+k]) return 0;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	slen=s.size();
	for(ll i=0;i<=slen-1;i++) s1[i]=s[slen-i-1];
	for(ll i=0;i<=slen-2;i++)
	{
		for(ll j=i+1;j<=slen-1;j++)
		{
			if(cmp(i,j)) ans++;
		}
	}
	cout<<ans;
	return 0;
}
