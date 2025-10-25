#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ll N=1e5+10;
struct zuhe{
	string school;
	ll a,b,t,sum;
	ll cnt;
}; 
zuhe b[N];
map<string,ll> mp;
string s,s2;
ll n,cnt,score;
bool cmp(zuhe x,zuhe y)
{
	if(x.sum>y.sum) return 1;
	if(x.sum==y.sum&&x.cnt<y.cnt) return 1;
	if(x.sum==y.sum&&x.cnt==y.cnt&&x.school<y.school) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s>>score>>s2;
		for(ll ii=0;ii<s2.size();ii++)
		{
			if(s2[ii]>='A'&&s2[ii]<='Z') s2[ii]=s2[ii]+32;
		}
		if(!mp[s2])
		{
			cnt++;
			mp[s2]=cnt;
		}
		b[mp[s2]].school=s2;
		if(s[0]=='A') b[mp[s2]].a+=score;
		else if(s[0]=='B') b[mp[s2]].b+=score;
		else if(s[0]=='T') b[mp[s2]].t+=score;
		b[mp[s2]].cnt++;
	}
	for(ll i=1;i<=cnt;i++) b[i].sum=(ll)(b[i].b*1.0/1.5)+b[i].a+(ll)(b[i].t*1.5);
	sort(b+1,b+cnt+1,cmp);
	ll pos=0;
	cout<<cnt<<"\n";
	for(ll i=1;i<=cnt;i++)
	{
		if(i==1) pos=1;
		else if(b[i].sum!=b[i-1].sum) pos=i;
		cout<<pos<<" "<<b[i].school<<" "<<b[i].sum<<" "<<b[i].cnt;
		if(i!=cnt) cout<<"\n";
	}
	return 0;
}
