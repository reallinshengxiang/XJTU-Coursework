#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10;
struct Ans{
	ll x,y;
	bool operator <(const Ans bb) const
	{
		if(x<bb.x) return 1;
		if(x==bb.x&&y<bb.y) return 1;
		return 0;
	}
};
ll x,y,n,m,k,cnt,a[N],d[N][N],xx[N],yy[N];
map<ll,ll> sex,vis;
vector<ll> e[2][N];
map<Ans,ll> mp;
void geshi(ll x)
{
	if(1000<=x) cout<<x;
	else if(100<=x) cout<<0<<x;
	else if(10<=x) cout<<00<<x;
	else cout<<000<<x;
}
ll to_ll(string s)
{
	ll flag=1,ans=0;
	if(s[0]=='-') 
	{
		flag=-1;
		for(ll i=1;i<=4;i++) ans=ans*10+s[i]-'0';
	}
	else
	{
		for(ll i=0;i<=3;i++) ans=ans*10+s[i]-'0';
	}
	return ans*flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		x=to_ll(s1);
		y=to_ll(s2);
		if(s1[0]=='-') sex[-x]=1;
		else sex[x]=0;
		if(s2[0]=='-') sex[-y]=1;
		else sex[y]=0;
		if(!vis[abs(x)])
		{
			cnt++;
			a[cnt]=abs(x);
			vis[abs(x)]=cnt;
		}
		if(!vis[abs(y)])
		{
			cnt++;
			a[cnt]=abs(y);	
			vis[abs(y)]=cnt;
	    }
	    d[vis[abs(x)]][vis[abs(y)]]=d[vis[abs(y)]][vis[abs(x)]]=1;
	    if(sex[abs(x)]==sex[abs(y)]) e[sex[abs(x)]][vis[abs(x)]].push_back(vis[abs(y)]),e[sex[abs(x)]][vis[abs(y)]].push_back(vis[abs(x)]);
	}
	cin>>k;
	while(k--)
	{
		cin>>x>>y;
		ll cnt1=0,cnt2=0;
		for(ll i=0;i<e[sex[abs(x)]][vis[abs(x)]].size();i++)
		{
			if(e[sex[abs(x)]][vis[abs(x)]][i]==vis[y]||e[sex[abs(x)]][vis[abs(x)]][i]==vis[x]) continue;
			cnt1++;
			xx[cnt1]=e[sex[abs(x)]][vis[abs(x)]][i];
		}
		for(ll i=0;i<e[sex[abs(y)]][vis[abs(y)]].size();i++)
		{
			if(e[sex[abs(y)]][vis[abs(y)]][i]==vis[x]||e[sex[abs(y)]][vis[abs(y)]][i]==vis[y]) continue;
			cnt2++;
			yy[cnt2]=e[sex[abs(y)]][vis[abs(y)]][i];
		}
		vector<Ans> ans;
		ans.clear();
		mp.clear();
		for(ll i=1;i<=cnt1;i++)
		{
			for(ll j=1;j<=cnt2;j++)
			{
				if(d[xx[i]][yy[j]]&&!mp[(Ans){a[xx[i]],a[yy[j]]}])
				{
					mp[(Ans){a[xx[i]],a[yy[j]]}]=1;
					ans.push_back((Ans){a[xx[i]],a[yy[j]]});
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<"\n";
		for(ll i=0;i<ans.size();i++) 
		{
			geshi(ans[i].x);
			cout<<" ";
			geshi(ans[i].y);
			cout<<"\n";
		}
	}
	return 0;
}
