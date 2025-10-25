#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll T,n,a[N],d[N],sum,pl[N],pr[N],f[N],l[N],rr[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(f,0,sizeof(f));
		for(ll i=1; i<=n; i++) cin>>a[i];
		for(ll i=1; i<=n; i++) cin>>d[i];
		a[0]=a[n+1]=0;
		for(ll i=1; i<=n; i++)
		{
			pl[i]=l[i]=i-1;
			pr[i]=rr[i]=i+1;
		}
		for(ll ii=1; ii<=n; ii++)
		{
			sum=0;
			for(ll i=1; i<=n; i++)
			{
				if(!f[i])
				{					
					if(d[i]<a[l[i]]+a[rr[i]])
					{
						f[i]=1;
						pr[pl[i]]=pr[i];
						pl[pr[i]]=pl[i];
						sum++;
					}
				}
			}
			for(ll i=1;i<=n;i++) l[i]=pl[i],rr[i]=pr[i];
			cout<<sum<<" ";
			if(sum==0) 
			{
				for(ll k=ii+1;k<=n;k++) cout<<"0 ";
				break;
			}
		}

		cout<<"\n";
	}
	return 0;
}
