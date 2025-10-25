#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,k,m,ans[N],aa[N],nex[N],px[N],l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	for(ll i=1;i<=n;i++) cin>>px[i];
	nex[1]=1+k;
	l=1,r=1+k;
	for(ll i=2;i<=n;i++)
	{
		while(r+1<=n&&px[i]-px[l]>px[r+1]-px[i]) l++,r++;
		if(px[i]-px[l]>=px[r]-px[i]) nex[i]=l;
		else nex[i]=r;
	}
	for(ll i=1;i<=n;i++) ans[i]=i;
	while(m)
	{
		if(m&1)
		{
			for(ll i=1;i<=n;i++) ans[i]=nex[ans[i]];			
		}
		memcpy(aa,nex,sizeof(nex));
		for(ll i=1;i<=n;i++) nex[i]=aa[aa[i]];
		m>>=1;
	}
	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
