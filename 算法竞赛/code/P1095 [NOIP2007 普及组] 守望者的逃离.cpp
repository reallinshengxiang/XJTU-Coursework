#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s1,s2,m,s,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>s>>t;
	for(ll i=1;i<=t;i++)
	{
		s1=s1+17;
		if(m>=10)
		{
			s2=s2+60;
			m=m-10;
		}
		else m=m+4;
		if(s2>s1) s1=s2;
		if(s1>s)
		{
			cout<<"Yes\n"<<i;
			return 0;
		}
	}
	cout<<"No\n"<<s1;
	return 0;
}
