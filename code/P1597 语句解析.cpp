#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<char,ll> mp;
string s;
char ch,ch1;
ll pos,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	pos=0;
	mp['a']=mp['b']=mp['c']=0;
	for(ll i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='a'||s[i]=='b'||s[i]=='c')
		{
			ch=s[i];
		    pos=i+3;
		    num=0;
		    if(s[pos]=='a'||s[pos]=='b'||s[pos]=='c') 
		    {
		    	ch1=s[pos];
		    	mp[ch]=mp[ch1];
		    	i=pos+1;
		    	continue;		    	
			}
		    while(s[pos]>='0'&&s[pos]<='9')	num=num*10+(s[pos]-'0'),pos++;
		    i=pos;
		    mp[ch]=num;
		}		
	}
	cout<<mp['a']<<" "<<mp['b']<<" "<<mp['c'];
	return 0;
}
