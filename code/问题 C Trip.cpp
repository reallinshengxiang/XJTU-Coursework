#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> v;
ll f[88][88],f1[88][88],f2[88][88],maxl,lens1,lens2;
string s1,s2;
void dfs(ll len1,ll len2,string s,ll len)
{
	if(len1<0||len2<0) return;
	if(len<=0)
	{
		v.push_back(s);
		return;
	}
	for(ll i=0;i<=25;i++)
	{
		ll p1=f1[i][len1];
		ll p2=f2[i][len2];
		if(f[p1][p2]>=len)
		{
			char ch='a'+i;
			dfs(p1-1,p2-1,ch+s,len-1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2;
	lens1=s1.size();
	lens2=s2.size();
	s1=" "+s1;
	s2=" "+s2;
	for(ll i=1;i<=lens1;i++)
	{
		for(ll j=1;j<=lens2;j++)
		{
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			if(s1[i]==s2[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	}
	for(ll i=0;i<=25;i++)
    {
    	for(ll j=1;j<=lens1;j++)
    	{
    		if(s1[j]=='a'+i) f1[i][j]=j;
    		else f1[i][j]=f1[i][j-1];
		}
		for(ll j=1;j<=lens2;j++)
    	{
    		if(s2[j]=='a'+i) f2[i][j]=j;
    		else f2[i][j]=f2[i][j-1];
		}
	}
	maxl=f[lens1][lens2];
	dfs(lens1,lens2,"",maxl);
	sort(v.begin(),v.end());
	for(ll i=0;i<v.size();i++) cout<<v[i]<<"\n";
	return 0;
}
