#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll d[N],n,m,ans,a,b,c,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll p1,p2;
	cin>>n>>m;
	cin>>p1;
	for(ll i=1;i<=m-1;i++)
	{
		cin>>p2;
		d[min(p1,p2)]++;
		d[max(p1,p2)]--;
		p1=p2;
	}
	for(ll i=1;i<=n-1;i++)
	{
		cin>>a>>b>>c;
		sum=sum+d[i];
		ans=ans+min(sum*a,sum*b+c);
	}
	cout<<ans;
	return 0;
}
