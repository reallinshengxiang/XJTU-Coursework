#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,a,b,len;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>len>>s;
		a=b=0;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='+') a++;
			else b++;
		}
		cout<<abs(a-b)<<"\n";
	}
	return 0;
}
