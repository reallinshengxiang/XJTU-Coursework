#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[8]={0,1,2,10,20,40,100,200},a[15010],f[15010],n,T,c,v,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(f,-1,sizeof(f));
		memset(a,0,sizeof(a));
		a[0]=1;
		ll sum=0;
		for(ll i=1;i<=7;i++)
		{
			cin>>x;
			for(ll j=1;j<=x;j++)
			{
				for(ll k=sum;k>=0;k--)
				{
					if(a[k]) a[k+b[i]]=1;
				}
				sum=sum+b[i];
			}			
		}
		f[0]=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			double cc;
			cin>>cc>>v;
			c=cc*2;
			for(ll k=sum;k>=c;k--)
			{
				if(f[k-c]!=-1) f[k]=max(f[k],f[k-c]+v);
			}
		}
		ll ans=-1;
		for(ll i=sum;i>=1;i--)
		{
			if(f[i]!=-1&&a[i]) ans=max(ans,f[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
 } 
