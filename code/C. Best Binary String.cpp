#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll a[N],T;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>s;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='1') a[i]=1;
			else if(s[i]=='0') a[i]=0;
			else
			{
				if(i==0) a[i]=0;
				else a[i]=a[i-1];
			}
		}
		for(ll i=0;i<s.size();i++) cout<<a[i];
		cout<<"\n";
	}
	return 0;
}
