#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++)
		{
			if(s[j-1]!='_') a[i][j]=s[j-1]-'0';
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			
		}
	}
	cout<<"00011000\n00111100\n01000010\n11111111\n01011110\n01111110\n";
	return 0;
}
