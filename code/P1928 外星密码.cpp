#include<bits/stdc++.h>
using namespace std;
#define ll long long
string jm()
{
	ll n;
	string s1,s="";
	char ch;
	while(cin>>ch)
	{
		if(ch=='[')
		{
			cin>>n;
			s1=jm();
			while(n--) s=s+s1;
		}
		else if(ch==']') return s;
		else s=s+ch;
	}
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<jm();
	return 0;
}
