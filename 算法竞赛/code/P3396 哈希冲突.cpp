#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rll register long long
const ll N=15e4+10;
ll n,m,block,a[N],b[N][55],x,y;
char cmd;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	block=pow(n,0.333333);
	for(rll i=1;i<=n;i++)
	{
		cin>>a[i];
		for(rll j=1;j<=block;j++) b[j][i%j]=b[j][i%j]+a[i];
	}
	while(m--)
	{
		cin>>cmd>>x>>y;
		if(cmd=='A')
		{
			if(x<block) cout<<b[x][y%x]<<"\n";
			else
			{
				ll ans=0;
				for(rll i=y;i<=n;i=i+x) ans=ans+a[i];
				cout<<ans<<"\n";
			}
		}
		else if(cmd=='C')
		{
			for(rll i=1;i<=block;i++) b[i][x%i]=b[i][x%i]-a[x]+y;
			a[x]=y;
		}
	}
	return 0;
} 
