#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=510;
ll d[N][N],s[N][N],r,c,a,b;
ll check(ll x)
{
	ll st=0,sum=0,num=0,cnt;
	for(ll i=1;i<=r;i++)
	{
		sum=0,cnt=0;
		for(ll j=1;j<=c;j++)
		{
			sum=sum+s[i][j]-s[st][j];
			if(sum>=x)
			{
				sum=0;
				cnt++;
			}
		}
		if(cnt>=b)
		{
			num++;
			st=i;
		}
	}
	if(num>=a) return 1;
	return 0;
}
int main()
{
	cin>>r>>c>>a>>b;
	ll mid,ans,pl=0,pr=s[r][c];
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++) cin>>d[i][j],pr=pr+d[i][j];
	}
	for(ll i=1;i<=r;i++)
	{
		for(ll j=1;j<=c;j++) s[i][j]=d[i][j]+s[i-1][j];		
	}		
	while(pl<=pr)
	{
		mid=(pl+pr)/2;
		if(check(mid))
		{
			pl=mid+1;
			ans=mid;
		}
		else pr=mid-1;
	}
	cout<<ans;
	return 0;
 } 
