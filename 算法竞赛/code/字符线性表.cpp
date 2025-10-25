#include<iostream>
#include<list>
#include<string>
using namespace std;
#define ll long long
list<char> lst;
list<char>::iterator it;
string s;
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,s);
	for(ll i=0;i<=s.size()-1;i++) lst.push_back(s[i]);
	for(it=lst.begin();it!=lst.end();it++) cout<<*it;
	cout<<"\n"<<lst.size()<<"\n";
	cin>>ch;
	lst.remove(ch);
	for(it=lst.begin();it!=lst.end();it++) cout<<*it;
	cout<<"\n"<<lst.size();
}
