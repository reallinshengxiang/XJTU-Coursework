#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string n;
string reverse(string x)
{
	string ans=x;
	for(ll i=0;i<x.size();i++) ans[i]=x[x.size()-1-i];
	return ans;
}
string add(string x,string y)
{
	x=reverse(x),y=reverse(y);
	string ans=x;
	ll xx=0;
	for(ll i=0;i<x.size();i++)
	{
		xx+=(ll)((x[i]-'0')+(y[i]-'0'));
		ans[i]=char(xx%10+'0');
		xx=xx/10;
	}
	if(xx) ans+=('0'+xx);
	ans=reverse(ans);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=10;i++)
	{
		string x=reverse(n);
		if(n==x) 
		{
			cout<<n<<" is a palindromic number.";
			return 0;
		}
		else 
		{
			cout<<n<<" + ";
			cout<<x<<" = ";
			n=add(n,x);
			cout<<n<<"\n";
		}
	}
	cout<<"Not found in 10 iterations.";
	return 0;
}
