#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll r,c,k,ans,a[N][N],b[N][N],d[N][N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>r>>c>>k;
	for(ll i=1;i<=r;i++)
	{
		cin>>s;
		for(ll j=1;j<=c;j++)
		{
			if(s[j-1]=='#') a[i][j]=b[i][j]=d[i][j]=1;
		}
	} 
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++) 
		{
			b[i][j]=b[i][j]+b[i][j-1];
			d[i][j]=d[i-1][j]+d[i][j];
		}
	}
	for(ll i=1;i<=r-k+1;i++)
	{
		for(ll j=1;j<=c;j++) 
		{
			if(a[i][j]==0)
			{
				if(d[i+k-1][j]-d[i-1][j]==0) ans++;
			}
		}
	}
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c-k+1;j++) 
		{
			if(a[i][j]==0)
			{
				if(b[i][j+k-1]-b[i][j-1]==0) ans++;
			}
		}
	}
    if(k==1) ans=ans/2;
	cout<<ans;
	return 0;
} 
