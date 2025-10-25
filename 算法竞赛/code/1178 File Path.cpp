#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll cnt,kk,ans[N],n,fa[N];
string s;
map<ll,ll> mp,pm;
vector<ll> v[N],son[N];
void geshi(ll x)
{
	if(x<10) cout<<"000"<<x;
	else if(x<100) cout<<"00"<<x;
	else if(x<1000) cout<<"0"<<x;
	else cout<<x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin.get();
		getline(cin,s);
		//cout<<i<<"  "<<s<<"\n";
		ll num=0,t=0; 
		for(ll j=0;j<s.size();j++)
		{
			if(s[j]==' ') num++;
			else t=t*10+(s[j]-'0');	
		}
		//cout<<num<<"  "<<t<<"\n";
		if(!mp[t])
		{
			cnt++;
			mp[t]=cnt;
			pm[cnt]=t;
		}
		v[num].push_back(cnt);
		if(num!=0) 
		{
			ll x=v[num-1][v[num-1].size()-1];
			fa[cnt]=x;
		}
		else fa[cnt]=0;
		//cout<<fa[cnt]<<"  "<<pm[cnt]<<"   "<<pm[fa[cnt]]<<"\n";
	}
	cin>>kk;
	while(kk--)
	{
		cin>>s;
		ll t=0;
		for(ll i=0;i<s.size();i++) t=t*10+(s[i]-'0');
		if(!mp[t]) 
		{
			cout<<"Error: "<<s<<" is not found.\n";
			continue;
		}
		cnt=0;
		cnt++;
		ans[cnt]=t;
		//cout<<i<<"   "<<t<<"\n";
		while(t!=0)
		{
			cnt++;
			t=pm[fa[mp[t]]];
			ans[cnt]=t;
		}
		for(ll i=cnt;i>=1;i--) 
		{
			geshi(ans[i]);
			if(i!=1) cout<<"->";
			else cout<<"\n";
		}
	}
	return 0;
}
