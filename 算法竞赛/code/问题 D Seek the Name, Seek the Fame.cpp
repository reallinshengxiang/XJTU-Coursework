#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll nex[400010],n,a[400010],cnt;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s)
	{
		memset(nex,0,sizeof(nex));
		memset(a,0,sizeof(a));
		cnt=0;
		nex[0]=nex[1]=0;
		for(ll i=1;i<=s.size()-1;i++)
		{
			ll j=nex[i];
			while(j&&s[i]!=s[j]) j=nex[j];
			if(s[i]==s[j]) nex[i+1]=j+1;
			else nex[i+1]=0;
		}
		ll j=s.size();
		while(j)
		{
			cnt++;
			a[cnt]=j;
			j=nex[j];
		}
		for(ll i=cnt;i>=1;i--) cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
	
