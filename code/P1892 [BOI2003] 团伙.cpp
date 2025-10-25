#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll s[N],n,m,a,b,ans;
char opt;
ll find_set(ll x)
{
	if(s[x]!=x) s[x]=find_set(s[x]);
	return s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=2*n;i++) s[i]=i;
	for(ll i=1;i<=m;i++)
	{
		cin>>opt>>a>>b;
		if(opt=='F') s[find_set(a)]=find_set(b);
		else
		{
			s[find_set(a+n)]=find_set(b);
			s[find_set(b+n)]=find_set(a);
		}
	}
	for(ll i=1;i<=n;i++) if(s[i]==i) ans++;
	cout<<ans;
	return 0;
}
