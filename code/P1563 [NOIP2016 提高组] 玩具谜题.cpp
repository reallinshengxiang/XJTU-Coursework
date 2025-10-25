#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct man{
	string name;
	ll towards;
};
man a[N];
ll n,m,pos,flag,aa,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=0;i<=n-1;i++)	
	{
		cin>>a[i].towards>>a[i].name;
		if(a[i].towards==0) a[i].towards=-1;
	}
	pos=0;
	flag=a[pos].towards;
	for(ll i=1;i<=m;i++)
	{
		cin>>aa>>s;
		if(aa==0) aa=-1;
		pos=((pos-flag*aa*s)%n+n)%n;
		flag=a[pos].towards;
	}
	cout<<a[pos].name;
	return 0;
}
