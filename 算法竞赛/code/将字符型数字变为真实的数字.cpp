#include<iostream>
using namespace std;
#define ll long long
ll ans,ans1,ans2;
string s1,s2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2;
	for(ll i=0;i<=s1.size()-1;i++) ans1=ans1*10+(s1[i]-'0');
	for(ll i=0;i<=s2.size()-1;i++) ans2=ans2*10+(s2[i]-'0');
	ans=ans1+ans2;
	cout<<ans;
	return 0;
}
