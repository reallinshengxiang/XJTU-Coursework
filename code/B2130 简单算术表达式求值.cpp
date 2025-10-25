#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>ch>>b;
	if(ch=='+') cout<<a+b;
	else if(ch=='-') cout<<a-b;
	else if(ch=='*') cout<<a*b;
	else if(ch=='/') cout<<a/b;
	else if(ch=='%') cout<<a%b;
	return 0;
}
