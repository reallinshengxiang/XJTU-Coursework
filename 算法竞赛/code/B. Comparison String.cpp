#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,ans,num,n;
string s;
char last;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		last=s[0];
		ans=1;
		num=1;
		for(ll i=1;i<=s.size()-1;i++)
		{
			if(s[i]==last) num++;
			else
			{
				ans=max(ans,num);
				num=1;
				last=s[i];
			}
		}
		ans=max(ans,num);
		cout<<ans+1<<"\n";
	}
	return 0; 
}
