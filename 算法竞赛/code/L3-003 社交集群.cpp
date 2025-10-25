#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll s[N],h,k,pos,p[N],n,cnt,b[N];
char ch; 
map<ll,ll> mp[N],vis;
bool cmp(ll x,ll y)
{
	if(x>y) return 1;
	return 0;
}
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	s[y]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) s[i]=i;
	for(ll i=1;i<=n;i++)
	{
		cin>>k>>ch;
		cnt=0;
		for(ll j=1;j<=k;j++) 
		{
			cin>>h;
			mp[i][h]=1;
			for(ll k=1;k<=i-1;k++) 
			{
				if(mp[k][h]) cnt++,p[cnt]=k;
			}
		}
		for(ll j=1;j<=cnt;j++) merge(p[j],i);
	}
	for(ll i=1;i<=n;i++) s[i]=find_set(s[i]);
	cnt=0;
	for(ll i=1;i<=n;i++)
	{
		if(!vis[s[i]])
		{
			cnt++;
			vis[s[i]]=cnt;
			b[cnt]++;
		}
		else 
		{
			pos=vis[s[i]];
			b[pos]++;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	cout<<cnt<<"\n";
	cout<<b[1]; 
	for(ll i=2;i<=cnt;i++) cout<<" "<<b[i];
	return 0;
}
