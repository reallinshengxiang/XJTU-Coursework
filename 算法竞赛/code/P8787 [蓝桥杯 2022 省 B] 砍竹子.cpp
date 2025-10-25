#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=2e5+10;
ll num[N],h[N],x,n,maxx,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>h[i];
		x=h[i];
		while(x!=1) x=sqrt(x/2+1),num[i]++;
		maxx=max(maxx,num[i]);
	}
	for(ll i=maxx;i>=1;i--)
	{
		for(ll j=1;j<=n;j++)
		{
			if(num[j]==i)
			{
				if(h[j]!=h[j+1]) ans++;
				num[j]--;
				h[j]=sqrt(h[j]/2+1);
			}
		}
	}
	cout<<ans;
	return 0;
}
