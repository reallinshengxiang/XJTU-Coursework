#include<iostream>
using namespace std;
#define ll long long
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x1,x2;
	getline(cin,s);
	x1=0;
	x2=s.size()-1;
	while(s[x1]==' ') x1++;
	while(s[x2]==' ') x2--;
	for(ll i=x1;i<=x2;i++) cout<<s[i];
	return 0;
}
