#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
ll a[N][N],b[N][N],c[N][N],n,m,last,num[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cin>>a[i][j];
	}
	for(ll i=1;i<=n;i++)
	{
		memset(num,0,sizeof(num));
        last=a[i][1];
		num[last]++;	
		for(ll j=2;j<=m;j++)
		{
			if(a[i][j]==last)
			{
				num[last]++;
				if(num[last]==3) b[i][j-2]=b[i][j-1]=b[i][j]=1;
				else if(num[last]>3) b[i][j]=1;
			}
			else
			{
				num[last]=0;
				last=a[i][j];
				num[last]++;
			}
		}
	}
	for(ll j=1;j<=m;j++)
	{
	    memset(num,0,sizeof(num));
        last=a[1][j];
		num[last]++;
		for(ll i=2;i<=n;i++)
		{
			if(a[i][j]==last)
			{
				num[last]++;
				if(num[last]==3) c[i-2][j]=c[i-1][j]=c[i][j]=1;
				else if(num[last]>3) c[i][j]=1;
			}
			else
			{
				num[last]=0;
				last=a[i][j];
				num[last]++;
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			if(!b[i][j]&&!c[i][j]) cout<<a[i][j]<<" ";
			else cout<<"0 ";
		} 
		cout<<"\n";
	}
	return 0;
} 
