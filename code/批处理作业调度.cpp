#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[5][5],ans=0x7f,sum,ed,ansb[5],b[5],f[5],ta[5],tb[5],tmp;
void dfs(ll step)
{
	if(step>=4)
	{
		for(ll i=1;i<=3;i++) cout<<b[i]<<" ";
		cout<<"\n"<<sum<<"\n";
		if(sum<ans)
		{
			ans=sum;
			for(ll i=1;i<=3;i++) ansb[i]=b[i];
		}
		return;
	}
	for(ll i=1;i<=3;i++)
	{
		if(f[i]) continue;
		f[i]=1;
		b[step]=i;
		ta[step]=ta[step-1]+t[i][1];
		tb[step]=max(tb[step-1],ta[step])+t[i][2];
		sum=sum+tb[step];
		dfs(step+1);
		sum=sum-tb[step];
		f[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=2;j++) cin>>t[i][j];
	}
	dfs(1);
	cout<<ans<<"\n";
	for(ll i=1;i<=3;i++) cout<<ansb[i]<<" ";
	return 0;
}
