#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,ss;
ll flag=1;
ll is_prime(ll x)
{
	if(x==1) return 0;
	if(x==2) return 1;
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
ll to_ll(string ss)
{
	ll ans=0;
	for(ll i=0;i<ss.size();i++) ans=ans*10+(ss[i]-'0');
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<=7;i++)
	{
		ss=s.substr(i,8-i);
		ll xx=to_ll(ss);
		cout<<ss<<" ";
		if(is_prime(xx)) cout<<"Yes\n";
		else cout<<"No\n",flag=0;
	}
	if(flag) cout<<"All Prime!";
	return 0;
} 
