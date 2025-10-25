#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,num;
string s,s1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=s.size()-1;i++)
	{
		if(s[i-1]!='V') continue;
		s1=s;
		s1[i]='K';
		num=0;
		for(ll i=0;i<=s1.size()-1;i++)
		{
			if(s1[i]=='V'&&s1[i+1]=='K')
			{
				num++;
				i++;
			} 
		}
		ans=max(num,ans);
	}
	for(ll i=0;i<=s.size()-2;i++)
	{
		if(s[i+1]!='K') continue;
		s1=s;
		s1[i]='V';
		num=0;
		for(ll i=0;i<=s1.size()-1;i++)
		{
			if(s1[i]=='V'&&s1[i+1]=='K')
			{
				num++;
				i++;
			} 
		}
		ans=max(num,ans);
	}
	cout<<ans;
	return 0;
}
