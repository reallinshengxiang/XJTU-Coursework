#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans,a[110][110];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) a[i][j]=s[j-1]-'A';		
	}
	for(ll i=2;i<=n-1;i++)
	{
		for(ll j=2;j<=m-1;j++)
		{
			if(a[i][j]<a[i-1][j]&&a[i][j]<a[i+1][j]&&a[i][j]<a[i][j-1]&&a[i][j]<a[i][j+1]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
