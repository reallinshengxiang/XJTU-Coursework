#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,string> a;
ll k,cnt;
string s;
int main()
{
	while(cin>>s)
	{
		if(s!="x")
		{
			cnt++;
			a[cnt]=s;
		}	
	}
	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
	return 0;
 } 
