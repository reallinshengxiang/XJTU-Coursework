#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct xiangmu{
	ll aa,bb,cc;
};
xiangmu xm[220];
bool cmp(xiangmu x,xiangmu y)
{
	if(x.aa>y.aa) return 1;
	return 0;
}
ll n,m,k,c[110],a,b,i,t,cnt,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=k;i++) cin>>c[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(b==999)
		{
			cout<<ans;
			return 0;
		}
		else if(b<=k)
		{
			cnt++;
			xm[cnt].aa=a;
			xm[cnt].bb=b;
		}
	}
	sort(xm+1,xm+1+cnt,cmp);
	i=1;
	t=0;
	while(t<m&&i<=cnt)
	{
	    if(c[xm[i].bb]>=1)
	    {
	    	ans=ans+xm[i].aa;
	    	c[xm[i].bb]--;
	    	t++;
		}
		i++;
	}
	cout<<ans;
	if(ans>=8000) cout<<"\nhao hao lian";
	return 0;
 } 
