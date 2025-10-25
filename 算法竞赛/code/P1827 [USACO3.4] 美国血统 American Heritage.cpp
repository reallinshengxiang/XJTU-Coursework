#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll len;
string s1,s2;
void houxu(ll st1,ll ed1,ll st2,ll ed2)
{
	if(ed1<st1||ed2<st2) return;
	ll pos=s2.find(s1[st1]);
	houxu(st1+1,st1+pos-st2,st2,pos-1);
	houxu(st1+pos-st2+1,ed1,pos+1,ed2);
	cout<<s1[st1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s2>>s1;
	len=s1.size();
	houxu(0,len-1,0,len-1);
	return 0;
}
