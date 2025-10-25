#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,s1,s2,ss,s0;
ll a,b,T,opt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T>>s;
	while(T--)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>s1;
			s0=s+s1;
			s=s0;
			cout<<s<<"\n";
		}
		else if(opt==2)
		{
			cin>>a>>b;
			s=s.substr(a,b);
			cout<<s<<"\n";
		}
		else if(opt==3)
		{
			cin>>a>>ss;
			s1=s.substr(0,a);
			s2=s.substr(a,s.size()-a+1);
			s=s1+ss+s2;
			cout<<s<<"\n";
		}
		else if(opt==4)
		{
			cin>>s1;
			ll ans=s.find(s1);
			if(ans>s.size()-1) ans=-1;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
