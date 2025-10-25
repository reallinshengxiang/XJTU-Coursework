#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll p1,p2,p3,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p1>>p2>>p3;
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		flag=1;
	    if(s[i]=='-'&&i>=1&&i<=s.size()-1)
		{
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]) 
			{
				if(s[i+1]-s[i]==1) flag=0;
				else
				{
					flag=0;
					if(p1==3) 
					{
						for(ll j=1;j<=((s[i+1]-s[i-1])-1)*p2;j++) cout<<"*"; 
					}
					else if(p1==1&&p3==1)
					{
						for(ll j=1;j<=(s[i+1]-s[i-1])-1;j++) 
						{
							for(ll k=1;k<=p2;k++) cout<<char(s[i-1]+j);
						}
					}
					else if(p1==1&&p3==2)
					{
						for(ll j=(s[i+1]-s[i-1])-1;j>=1;j--) 
						{
							for(ll k=p1;k<=p2;k++) cout<<char(s[i-1]+j);
						}
					}
					else if(p1==2&&p3==1)
					{
						for(ll j=1;j<=(s[i+1]-s[i-1])-1;j++) 
						{
							for(ll k=1;k<=p2;k++) cout<<char(s[i-1]+'A'-'a'+j);
						}
					}
					else if(p1==2&&p3==2)
					{
						for(ll j=(s[i+1]-s[i-1])-1;j>=1;j--) 
						{
							for(ll k=1;k<=p2;k++) cout<<char(s[i-1]+'A'-'a'+j);
						}
					}
				}
			}
			else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]) 
			{
				if(s[i+1]-s[i]==1) flag=0;
				else
				{
					flag=0;
					if(p1==3) 
					{
						for(ll j=1;j<=((s[i+1]-s[i-1])-1)*p2;j++) cout<<"*"; 
					}
					else if(p3==1)
					{
						for(ll j=1;j<=(s[i+1]-s[i-1])-1;j++) 
						{
							for(ll k=1;k<=p2;k++) cout<<char(s[i-1]+j);
						}
					}
					else if(p3==2)
					{
						for(ll j=1;j<=(s[i+1]-s[i-1])-1;j++) 
						{
							for(ll k=p2;k>=1;k--) cout<<char(s[i-1]+j);
						}
					}
				}
			}
		}
		if(flag) cout<<s[i]; 
	}
	return 0;
}
