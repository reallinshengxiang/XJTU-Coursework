#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll num;
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9') 
		{
			num=s[i]-'0';
			ch=s[i-1];
			for(ll j=1;j<=num-1;j++) cout<<ch;
		}
		else cout<<s[i];		
	}
	return 0; 
}
