#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[33],n,pos,k,ans,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	num[0]=0;
	for(ll i=1;i<=30;i++) num[i]=(1<<i)-1;
	while(m--)
	{
		cin>>n>>k;
		pos=num[n-1]+k;
		ll ans=0;
		while(pos!=0)
		{
			ans=ans+(pos%2);
			pos=pos/2;
		}
		if(ans%2) cout<<"RED\n";
		else cout<<"BLACK\n";
	}
	return 0;
}
