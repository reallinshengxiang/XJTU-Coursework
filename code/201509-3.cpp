#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
map<string,string> mp;
string s[N],ss,s1,s2,ss1;
ll n,cnt,p[5],m,pos1,pos2,pos;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	cin.get();
	for(ll i=1;i<=m;i++) 	getline(cin,s[i]);
    for(ll i=1;i<=n;i++)
    {
    	getline(cin,ss);
    	cnt=0;
    	for(ll i=0;i<ss.size();i++)
    	{
    		if(ss[i]=='"')
    		{
    			cnt++;
    			p[cnt]=i;
			}
			
		}
		s1=ss.substr(0,p[1]-1);
		s2=ss.substr(p[1]+1,p[2]-p[1]-1);
		mp[s1]=s2;
	}
	for(ll i=1;i<=m;i++)
	{
		pos=0,pos2=s[i].size()-1;
		for(ll j=0;j<s[i].size();j++)
		{
			if(s[i][j]=='{'&&s[i][j+1]=='{') 
			{
				pos1=j+2;
				for(ll k=j+3;k<s[i].size();k++) 
				{
					if(s[i][k]=='}'&&s[i][k+1]=='}')
					{
						pos2=k-2;
						break;
					}
				}
				ss=s[i].substr(pos1+1,pos2-pos1);
				ss1=s[i].substr(pos,pos1-2-pos);
				cout<<ss1<<mp[ss];
				pos=pos2+4;
			}		
		}
		ss1=s[i].substr(pos,pos2-pos+1);
		cout<<ss1<<"\n";
	}
	return 0;
}
