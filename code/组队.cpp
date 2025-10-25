#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,x[22][10],p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("team.txt","r",stdin);
	for(ll i=1;i<=20;i++)
	{
		cin>>p;
		for(ll j=1;j<=5;j++) cin>>x[i][j];
	}
	for(ll a=1;a<=20;a++)
	{
		for(ll b=1;b<=20;b++)
		{
			if(a==b) continue;
			for(ll c=1;c<=20;c++)
			{
				if(c==a||c==b) continue;
				for(ll d=1;d<=20;d++)
				{
					if(d==a||d==c||d==b) continue;
					for(ll e=1;e<=20;e++)
					{
						if(e==a||e==b||e==c||e==d) continue;
						ans=max(ans,x[a][1]+x[b][2]+x[c][3]+x[d][4]+x[e][5]);
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
