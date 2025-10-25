#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
string s;
char a[N],b[N];
ll len,ans;
ll check(ll l,ll r)
{
	for(ll i=l;i<=l+(r-l-1)/2;i++)
	{
		if(a[r-(i-l)]>a[i]) return 0;
		if(a[r-(i-l)]<a[i]) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size();
	for(ll i=0;i<=len-1;i++) a[i]=s[i];
	for(ll i=0;i<=len-2;i++)
	{
		for(ll j=i+1;j<=len-1;j++)
		{
			if(check(i,j)) ans++;
		}
	}
	cout<<ans;
	return 0;
}
