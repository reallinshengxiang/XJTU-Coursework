#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll len,pos1,pos2,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	len=s.size()-1;
	for(ll i=0;i<s.size();i++)
	{
		pos1=0;
		pos2=len;
		for(ll j=i-1;j>=0;j--)
		{
			if(s[i]==s[j])
			{
				pos1=j+1;
				break;
			}
		}
		for(ll j=i+1;j<=len;j++)
		{
			if(s[i]==s[j])
			{
				pos2=j-1;
				break;
			}
		}
		ans=ans+(i-pos1+1)*(pos2-i+1);
	}
	cout<<ans;
	return 0;
}
