#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll cnt;
string s,s1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=s.size()-1;i>=0;i--)
	{
		s1=s[i]+s1;
		cnt++;
		if(cnt%3==0&&i!=0) s1=","+s1;
	}
	cout<<s1;
	return 0;
}
