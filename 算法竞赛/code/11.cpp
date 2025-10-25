#include<bits/stdc++.h>
using namespace std;
#define ll long long
string ss,s;
ll sum,ans=10000000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=64;i++)
	{
		sum=0;
		cin>>s;
		for(ll i=0;i<=5;i++) sum=sum+(s[i]-'0');
		cout<<i<<" "<<s<<" "<<ans<<"  ";
		if(sum<ans)
		{
			ans=sum;
			ss=s;
		}
		cout<<sum<<"\n";
	}
	cout<<ss;
	return 0;
}
