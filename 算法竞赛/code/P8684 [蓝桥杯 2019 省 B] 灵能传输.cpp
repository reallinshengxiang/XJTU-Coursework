#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll T,sum[N],x,pl,pr,ans,pos,n,l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>x,sum[i]=sum[i-1]+x;
		sort(sum+1,sum+n);
		l=min(sum[0],sum[n]);
		r=max(sum[0],sum[n]);
		x=lower_bound(sum+1,sum+n,l)-sum;
		pl=l,pr=sum[x];
		pos=x;
		ans=0;
		while(pos>=1)
		{
			if(pl<pr) swap(pl,pr);
			ans=max(ans,pl-sum[pos]);
			pl=sum[pos];
			pos--;
		}
		ans=max(ans,max(pl-pr,pr-pl));
		pl=sum[x],pr=r;
		pos=x+1;
		while(pos<=n-1)
		{
			if(pl>pr) swap(pl,pr);
			ans=max(ans,sum[pos]-pl);
			pl=sum[pos];
			pos++;
		}
		ans=max(ans,max(pl-pr,pr-pl));
		if(x==n) ans=max(ans,r-sum[n-1]);
		cout<<ans<<"\n";
	}
	return 0;
}
