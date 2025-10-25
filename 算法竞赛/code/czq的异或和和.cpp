#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=0,last=0,last1,sum=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=0;i<=n;i++)
	{
		last=ans;		
		for(ll j=0;j<=n;j++) ans=ans+(i^j);		
		cout<<ans-last<<"        ";
		
		cout<<ans-last-78<<"          "<<i<<"    "<<sum<<"\n";
		sum=sum+ans-last-last1;
		last1=ans-last;
	}
	cout<<ans;
	return 0;
}
