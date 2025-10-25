#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,x,y;
string a,b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		ll cnt1=0,cnt2=0;
		cin>>n>>a>>b;
		for(ll i=0;i<=n-1;i++)
		{
			x=a[i]-'0';
			y=b[i]-'0';
			if(x-y<0) cnt1++;
			else if(x-y>0) cnt2++;
		}
		cout<<max(cnt1,cnt2)<<"\n";
	}
	return 0;
}
