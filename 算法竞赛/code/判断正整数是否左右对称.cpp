#include<iostream>
using namespace std;
#define ll long long
string s,s1;
ll len;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size();
	for(ll i=0;i<=(len-1)/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			cout<<"0";
			return 0;
		}
	}
	cout<<"1";
	return 0;
}
