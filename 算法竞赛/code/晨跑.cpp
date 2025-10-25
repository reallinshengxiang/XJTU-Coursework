#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},ans=0,sum=0; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=12;i++)
	{
		for(ll j=1;j<=a[i];j++)
		{
			if(j==1||j==11||j==21||j==31) ans++;
			else if((sum+j)%7==1||(sum+j)%7==2) ans++;
		}
		sum=sum+a[i];		
	}
	cout<<ans;
	return 0;
}
