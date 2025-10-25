#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,s1;
ll num;
map<string,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["Jan"]=1;
	mp["Feb"]=2;
	mp["Mar"]=3;
	mp["Apr"]=4;
	mp["May"]=5;
	mp["Jun"]=6;
	mp["Jul"]=7;
	mp["Aug"]=8;
	mp["Sep"]=9;
	mp["Oct"]=10;
	mp["Nov"]=11;
	mp["Dec"]=12;
	cin>>s;
	s1=s.substr(0,3);
	num=stoll(s.substr(3,2));
	cout<<mp[s1]<<" "<<num;
	return 0;
}
