#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1||n==0||n==2||n==3||n==4) 
	{
	   cout<<"-1"; 
	   return 0;	
	}
	ans=0;
	do
	{		
		x=n/2;
		y=n-x;
		n=x*y;
		ans++;
	}while(n<1000000000);
	cout<<ans;
	return 0; 
}
