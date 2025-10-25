#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll T,f[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>s;
		ll ch,last=26,ans=1;
		memset(f,0,sizeof(f));
		for(ll i=0;i<=s.size()-1;i++)
		{
			ch=s[i]-'a';
			if(ch==last) ans++; 
		    else if(ch!=last)
		    {
		    	if(f[last]<ans) f[last]=ans;
				ans=1;
				last=ch;
			}
		}
		f[ch]=max(f[ch],ans);
		ll cnt=0,sum=0;
		for(ll i=0;i<=25;i++)
		{
			if(f[i])
			{
				cnt++;
				sum=sum+f[i];
			}
		}
		cout<<sum-cnt<<"\n";
	}
	return 0;
}
