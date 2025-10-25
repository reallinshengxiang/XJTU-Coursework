#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct zimu{
	string ss[7];
};
zimu a[30];
string s,s1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=26;i++)
	{
		for(ll j=1;j<=7;j++) cin>>a[i].ss[j-1];
	}
	cin.get();
	getline(cin,s);
	s+='.';
	ll st=0,flag=0,len=0,cnt=0,ed=0;
	for(ll i=s.size()-1;i>=0;i--)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			ed=i;
			break;
		}
	}
	for(ll i=0;i<s.size();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			if(!flag)
			{
				flag=1;
				st=i;
				len=1;
				cnt++;
			}
			else len++;
		}
		else
		{
			if(flag)
			{
				flag=0;
				s1=s.substr(st,len);
				for(ll j=0;j<7;j++)
				{
					for(ll k=0;k<s1.size();k++) 
					{
						cout<<a[(s1[k]-'A'+1)].ss[j];
						if(k!=s1.size()-1) cout<<" ";
					}
					if(j!=6) cout<<"\n";
				}
				if(i<ed) cout<<"\n\n";
			}
		}
	}
	return 0;
}
