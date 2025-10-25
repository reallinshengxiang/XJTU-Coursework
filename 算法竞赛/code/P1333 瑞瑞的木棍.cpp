#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
unordered_map<string,ll> mp;
ll f[N],num,cnt,degree[N];
string s1,s2;
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	if(x!=y) f[x]=y;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=N-1;i++) f[i]=i; 
	while(cin>>s1>>s2)
	{
		if(mp[s1]==0)
		{
			cnt++;
			mp[s1]=cnt;
		}
		if(mp[s2]==0)
		{
			cnt++;
			mp[s2]=cnt;
		}
		degree[mp[s1]]++;
		degree[mp[s2]]++;
		if(find_set(mp[s1])!=find_set(mp[s2]))
		{
			merge(mp[s1],mp[s2]);
			num++;
		}
	}
	if(cnt==0)
	{
		cout<<"Possible";
		return 0;
	}
	if(num!=cnt-1) 
	{
		cout<<"Impossible";
		return 0;
	}
	num=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(degree[i]%2) num++;
	}
	if(num>=3) cout<<"Impossible";
	else cout<<"Possible";
	return 0;
}
