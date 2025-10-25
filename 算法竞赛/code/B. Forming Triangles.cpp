#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll T,cnt,ans,a[N],num[N],n,sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		map<ll,ll> mp;
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		cnt=0;
		for(ll i=1;i<=n;i++)
		{
			if(!mp[a[i]])
			{
				mp[a[i]]=1;
				cnt++;
				num[cnt]++;
			}
			else num[cnt]++;
		}
		ans=0;
		sum[0]=0;
		for(ll i=1;i<=cnt;i++) sum[i]=sum[i-1]+num[i];
		for(ll i=1;i<=cnt;i++)
		{
			if(num[i]>=2) ans=ans+(num[i]*(num[i]-1)/2)*sum[i-1];
			if(num[i]>=3) ans=ans+(num[i]*(num[i]-1)*(num[i]-2))/6;
		}
		cout<<ans<<"\n";
		memset(num,0,sizeof(num));		
	}
	return 0; 
}
