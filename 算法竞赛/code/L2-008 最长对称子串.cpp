#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll len,maxx;
ll check(ll pos,ll num)
{
	if(pos-num<0||pos+num>len) return 0; 
	for(ll j=1;j<=num;j++)
	{
		if(s[pos-j]!=s[pos+j]) return 0;
	}
	return 1;
}
ll check2(ll pos,ll num)
{
	if(pos-num+1<0||pos+num>len) return 0; 
	for(ll j=0;j<=num-1;j++)
	{
		if(s[pos-j]!=s[pos+j+1]) return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	len=s.size();
	for(ll i=0;i<s.size();i++)
	{
		for(ll j=0;j<=i;j++)
		{
			if(!check(i,j)) break;
			maxx=max(maxx,j*2+1);
		}
	}
	for(ll i=0;i<s.size();i++)
	{
		for(ll j=1;j<=i+1;j++)
		{
			if(!check2(i,j)) break;
			maxx=max(maxx,j*2);
		}
	}
	cout<<maxx;
	return 0;
}
