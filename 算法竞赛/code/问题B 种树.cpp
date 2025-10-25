#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct sugg{
	ll b,e,t;
};
sugg s[30030];
bool cmp(sugg a,sugg b)
{
	return a.e<b.e;
}
ll tree[30030],ans,n,h;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>h;
	for(ll i=1;i<=h;i++) cin>>s[i].b>>s[i].e>>s[i].t;
	sort(s+1,s+h+1,cmp);
	for(ll i=1;i<=h;i++)
	{
		for(ll j=s[i].e;j>=s[i].b;j--)
		{
			if(tree[j]) s[i].t--;
		}
		for(ll j=s[i].e;j>=s[i].b;j--)
		{
			if(s[i].t<=0) break;
			if(!tree[j])
			{
				tree[j]=1;
				s[i].t--;
			}
		}
	}
	for(ll i=1;i<=n;i++) ans=ans+tree[i];
	cout<<ans;
	return 0;
}
