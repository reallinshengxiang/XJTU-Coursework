#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll cnt,x,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(ll i=0;i<=10;i++)
	{
		if(i==1||i==5) continue;
		cnt++;
		sum=sum+(s[i]-'0')*cnt;
	}
	x=s[12]-'0';
	if(s[12]=='X') x=10;
	if(sum%11==x) cout<<"Right";
	else 
	{
		for(ll i=0;i<=11;i++) cout<<s[i];
		if(sum%11==10) cout<<"X"; 
		else cout<<sum%11;
	}
	return 0;
}
