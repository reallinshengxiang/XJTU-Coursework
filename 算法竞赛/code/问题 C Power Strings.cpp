#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll nex[1000010],n;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s)
	{
		if(s==".") break;
		memset(nex,0,sizeof(nex));
		nex[0]=nex[1]=0;
		for(ll i=1;i<=s.size()-1;i++)
		{
			ll j=nex[i];
			while(j&&s[i]!=s[j]) j=nex[j];
			if(s[i]==s[j]) nex[i+1]=j+1;
			else nex[i+1]=0;
		}
		n=s.size();
		if(n%(n-nex[n])) cout<<1<<"\n";
		else cout<<n/(n-nex[n])<<"\n";
	}
	return 0;
}
	
