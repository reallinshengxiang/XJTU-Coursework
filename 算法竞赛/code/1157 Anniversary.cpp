#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
string s[N],ss[N],a[N];
map<string,ll> vis;
ll n,m,cnt;
bool cmp(const string s1,const string s2)
{
	string ss1=s1.substr(6,8),ss2=s2.substr(6,8);
	if(ss1<ss2) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i];
		vis[s[i]]=1; 
	}
	cin>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>ss[i];
		if(vis[ss[i]])
		{
			cnt++;
			a[cnt]=ss[i];
		}
	}
	sort(ss+1,ss+m+1,cmp);
	cout<<cnt<<"\n";
	if(cnt==0) cout<<ss[1];
	else
	{
		sort(a+1,a+cnt+1,cmp);
		cout<<a[1];
	}
	return 0;
}
