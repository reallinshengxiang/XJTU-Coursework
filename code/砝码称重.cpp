#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w[110],sum,f[200010],n,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i+n]=-w[i];
		sum=sum+w[i];
    }
    f[0]=1;
	for(ll i=1;i<=2*n;i++)
	{
		if(w[i]>0)
		{
			for(ll j=sum;j>=w[i];j--)
	       {
	    	f[j]=max(f[j],f[j-w[i]]);
		   }
		}	    
		else
		{
			for(ll j=w[i];j<=sum;j++)
			{
				f[j]=max(f[j],f[j-w[i]]);
			}
		}
	}
	for(ll i=1;i<=sum;i++)
	{
		if(f[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
