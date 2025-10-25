#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll ans,a[N],b[N],n,num[10];
map<ll,ll> vis;
ll num_6(ll x)
{
	ll ans=0;
	while(x)
	{
		if(x%10==6) ans++;
		x=x/10;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=num_6(a[i]); 
		if(b[i]>6) b[i]=6;
		num[b[i]]++;
	}
	num[0]=n;
	for(ll i=6;i>=2;i--)
	{
		if(num[i]==0) continue;
		for(ll j=0;j<=i&&num[i]>0;j++)
		{
			for(ll k=0;k<=j&&k<=6-j-i&&num[i]>0;k++)
			{
				if(i+j+k>=6)
				{
					if(num[i]&&num[j]&&num[k]&&i>j&&j>k) 
					{
						ll nn=min(min(num[i],num[j]),num[k]);
						num[i]=num[i]-nn;
						num[j]=num[j]-nn;
						num[k]=num[k]-nn;
						ans=ans+nn;
					}
					else if(num[i]&&num[j]&&num[k]&&i==j&&j>k) 
					{
						ll nn=min(num[i]/2,num[k]);
						num[i]=num[i]-nn;
						num[j]=num[j]-nn;
						num[k]=num[k]-nn;
						ans=ans+nn;
					}
					else if(num[i]&&num[j]&&num[k]&&i==j&&j==k) 
					{
						ll nn=num[i]/3;
						num[i]=num[i]-nn;
						num[j]=num[j]-nn;
						num[k]=num[k]-nn;
						ans=ans+nn;
					}
					else if(num[i]&&num[j]&&num[k]&&i>j&&j==k) 
					{
						ll nn=min(num[i],num[j]/2);
						num[i]=num[i]-nn;
						num[j]=num[j]-nn;
						num[k]=num[k]-nn;
						ans=ans+nn;
					}
				}
			}
		}
		if(num[i]) num[i-1]=num[i-1]+num[i],num[i]=0;
	}
	cout<<ans;
	return 0;
} 
