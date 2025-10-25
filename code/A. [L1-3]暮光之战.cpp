#include<bits/stdc++.h>
using namespace std;
#define ll long long
string ss,s1="United States",s2="USSR",s;
ll a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		getline(cin,ss);
		if(ss=="-1") break;
		if(ss.find(s1)!=-1) a++;
		else if(ss.find(s2)!=-1) b++;
		else
		{
			a++;
			b++;
		}
	}
	cout<<"United States: "<<a<<"\n";
	cout<<"USSR: "<<b;
	return 0;
 } 
