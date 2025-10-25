#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[5]={0,0,0,1,-1};
ll dy[5]={0,1,-1,0,0};
ll a[6][6],b[6][6],cnt,n,xx,yy,flag,ans;
string s;
void change(ll x,ll y)
{
	for(ll i=0;i<=4;i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		if(xx>=0&&xx<=4&&yy>=0&&yy<=4) b[xx][yy]=1-b[xx][yy];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		for(ll i=0;i<=4;i++)
		{
			cin>>s;
			for(ll j=0;j<=4;j++)  a[i][j]=s[j]-'0';
		}
		ans=7;
		for(ll k=0;k<=31;k++)
		{
			memcpy(b,a,sizeof(a));
			cnt=0;
			for(ll i=0;i<=4;i++)
			{
				if((k>>i)&1) 
				{
					cnt++;
					change(0,i);
				}
			}
			for(ll i=0;i<=3;i++)
			{
				for(ll j=0;j<=4;j++)
				{
					if(b[i][j]==0) 
					{
						cnt++;
						change(i+1,j);
					}
				}
			}
			flag=1;
			for(ll i=0;i<=4;i++)
			{
				if(b[4][i]==0)
				{
					flag=0;
					break;
				} 
			}
			if(flag) ans=min(ans,cnt);		
		}
		if(ans<=6) cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
