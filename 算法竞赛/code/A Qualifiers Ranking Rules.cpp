#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e4+10;
struct bd{
	string school;
	ll rank1,rank2;
};
bd a[N];
map<string,ll> mp;
ll n,m,cnt,num;
string s;
bool cmp(bd a,bd b)
{
	if(min(a.rank1,a.rank2)!=min(b.rank1,b.rank2)) return min(a.rank1,a.rank2)<min(b.rank1,b.rank2);
	return a.rank1<b.rank1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		if(!mp[s]) 
		{
			cnt++;
			mp[s]=cnt;
			a[cnt].school=s;
			a[cnt].rank1=cnt;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		if(!mp[s]) 
		{
			num++;
			cnt++;
			mp[s]=cnt;
			a[cnt].school=s;
			a[cnt].rank2=num;
		}
		else if(!a[mp[s]].rank2) num++,a[mp[s]].rank2=num;
	}
	for(ll i=1;i<=cnt;i++) 
	{
		if(a[i].rank1==0) a[i].rank1=N;
		if(a[i].rank2==0) a[i].rank2=N;
	}
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++) cout<<a[i].school<<"\n";
	return 0;
}
