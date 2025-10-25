#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n,i,len;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>n;
	len=s.size();
	while(len<n)
	{
		i=len;
		while(n>i) i=i*2;
		i=i/2;
		n=n-(i+1);
		if(n==0) n=i;
	}
	cout<<s[n-1];
	return 0;
}
