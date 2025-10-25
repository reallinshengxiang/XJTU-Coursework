#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110][110],b[110][110],f,v,maxx,k,d[110],c[110][110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>f>>v;
	for(ll i=1;i<=f;i++)
	{
		for(ll j=1;j<=v;j++) cin>>a[i][j];
	}
	memset(b,128,sizeof(b)); 
	for(ll i=1;i<=v-f+1;i++) b[1][i]=a[1][i];
	for(ll i=2;i<=f;i++)
	{
		for(ll j=i;j<=v-f+i;j++)
		{
			for(ll k=i-1;k<=j-1;k++)
			{
				if(b[i][j]<b[i-1][k]+a[i][j])
				{
					b[i][j]=b[i-1][k]+a[i][j];
					c[i][j]=k;
				}
			}
		}
	}
	maxx=-0x7f;
	for(ll i=f;i<=v;i++)
	{
		if(b[f][i]>maxx)
		{
			maxx=b[f][i];
			k=i;
		}
	}
	cout<<maxx<<"\n";
	for(ll i=1;i<=f;i++)
	{
		d[i]=k;
		k=c[f-i+1][k];
	}
	for(ll i=f;i>=1;i--) cout<<d[i]<<" ";
	return 0; 
 } 
