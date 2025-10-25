#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct shu{
	ll num,id,bb;
};
shu a[N];
ll n,k,T,b[N];
bool cmp1(shu a,shu b)
{
	return a.num<b.num;
}
bool cmp2(shu a,shu b)
{
	return a.id<b.id;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].num;
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp1);
		for(ll i=1;i<=n;i++) cin>>b[i];
		sort(b+1,b+n+1);
		for(ll i=1;i<=n;i++) a[i].bb=b[i];
		sort(a+1,a+n+1,cmp2);
		for(ll i=1;i<=n;i++) cout<<a[i].bb<<" ";
		cout<<"\n";
	}
	return 0;
}
