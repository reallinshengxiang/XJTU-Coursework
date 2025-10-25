#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r,pl,pr,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>l>>r;
	if(r-l<=10) 
	{
		for(ll i=l;i<=r;i++)
		{
			if(i%4==0||i%2==1) ans++;
		}
		cout<<ans;
		return 0;
	}
	pl=l;
	pr=r;
	while(pl%4!=0) pl++;
	while(pr%4!=0) pr--;
	for(ll i=l;i<=pl-1;i++) 
	{	
	    if(i%4==0||i%2==1) ans++;
	}
	for(ll i=pr+1;i<=r;i++)
	{
		if(i%4==0||i%2==1) ans++;
	}
	ans=ans+(pr-pl)/4+1+(pr-pl)/2;
	cout<<ans;
	return 0;
}
