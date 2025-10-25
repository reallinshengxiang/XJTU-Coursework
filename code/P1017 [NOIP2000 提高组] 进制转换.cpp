#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll n,m,x,len;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cout<<n<<"=";
	while(n!=0)
	{
		x=n%m;
		n=n/m;
		if(x<0) 
		{
			x=x-m;
			n++;
		}
		len++;
		if(x<10) s[len]=char(x+48);
		else s[len]=char(x+55);
	}
	for(ll i=len;i>=1;i--) cout<<s[i];
	cout<<"(base"<<m<<")";
	return 0;
} 
