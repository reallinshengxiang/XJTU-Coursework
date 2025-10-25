#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
string s;
ll n1,n3,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	n=s.size();
	n1=(n+2)/3;
	n3=n-n1*2;
	for(ll i=1;i<=n1-1;i++)
	{
		cout<<s[i-1];
		for(ll j=1;j<=n3;j++) cout<<" ";
		cout<<s[n-i]<<"\n";
	}
	for(ll i=n1;i<=n1+n3+1;i++) cout<<s[i-1];  
	return 0;
}
