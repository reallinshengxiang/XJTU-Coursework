#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5010],b[5010],k,num,st,ed,l,r,n,m,ans[22],maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)  cin>>a[i];
	for(ll i=1;i<=m;i++)  cin>>b[i];
	cin>>k;
	while(k--)
	{
		memset(ans,0,sizeof(ans));
		cin>>l>>r;
		st=b[l];
		ed=b[r];
		for(ll i=st+1;i<=ed;i++)
		{
			num=a[i];
			maxx=0;
			for(ll j=0;j<=num;j++)	maxx=max(maxx,ans[j]+1);
			ans[num]=maxx;		
		}
		ll xx=0;
		for(ll i=0;i<=10;i++)  xx=max(xx,ans[i]);
		cout<<xx<<"\n";
	}
	return 0;
}
