#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[30],cnt,st,xx;
map<string,ll> mp;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["one"]=mp["a"]=mp["another"]=mp["first"]=1;
	mp["two"]=mp["both"]=mp["second"]=2;
	mp["three"]=mp["third"]=3;
	mp["four"]=4;
	mp["five"]=5;
	mp["six"]=6;
	mp["seven"]=7;
	mp["eight"]=8;
	mp["nine"]=9;
	mp["ten"]=10;
	mp["eleven"]=11;
	mp["twelve"]=12;
	while(cin>>s)
	{
		for(ll i=0;i<=s.size();i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]=(s[i]-'A')+'a'; 
		}
		if(mp[s])
		{
			xx=(mp[s]*mp[s])%100;
			if(xx==0) continue;
			cnt++;
			a[cnt]=xx;
		}
	}
	sort(a+1,a+cnt+1);
	cout<<a[1];
	for(ll i=2;i<=cnt;i++)
	{
		if(a[i]<10) cout<<"0";
		cout<<a[i];
	}
} 
