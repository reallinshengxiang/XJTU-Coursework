#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,len,flag;
string a,b,c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>len>>a>>b>>c;
		flag=0;
		for(ll i=0;i<=len-1;i++)
		{
			if(a[i]!=b[i]&&a[i]!=c[i]&&b[i]!=c[i]) 
			{
				flag=1;
				break;
			}
			else if(a[i]==b[i]&&a[i]!=c[i])
			{
				flag=1;
				break;
			}
		} 
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0; 
}
