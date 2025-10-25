#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#pragma GCC optimize(2)
struct fc{
	ll reactant[110];
};
fc p,f[110][110];
map<ll,ll> mp;
ll n,m,a[110],b[110],k,vis[110],ans[110];
string s;
void geshi(ll x)
{
	if(x<=9) cout<<0<<x;
	else cout<<x; 
}
void print()
{
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=f[b[i]][ans[i]].reactant[0];j++) 
		{
		    geshi(f[b[i]][ans[i]].reactant[j]); 	
		    if(j!=f[b[i]][ans[i]].reactant[0]) cout<<" + ";
		    else cout<<" -> "; 
		}
		geshi(b[i]);
		cout<<"\n"; 
	}
	exit(0);
}
ll check()
{
	memset(vis,0,sizeof(vis));
	//print();
	for(ll i=1;i<=n;i++) vis[a[i]]=1;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=f[b[i]][ans[i]].reactant[0];j++) 
		{
			vis[f[b[i]][ans[i]].reactant[j]]--;
			//cout<<f[b[i]][ans[i]].reactant[j]<<"   "<<vis[f[b[i]][ans[i]].reactant[j]]<<"\n";
			if(vis[f[b[i]][ans[i]].reactant[j]]<0) return 0;
		}
	}
	return 1;
}

void dfs(ll step)
{
	if(step==m+1) 
	{
		if(check()) print(); 
		return;
	}
	for(ll i=1;i<=mp[b[step]];i++)
	{
		ll flag=1;
		ans[step]=i;
		for(ll j=1;j<=f[b[step]][ans[step]].reactant[0];j++) 
		{
			vis[f[b[step]][ans[step]].reactant[j]]--;
			if(vis[f[b[step]][ans[step]].reactant[j]]<0) flag=0;
		}
		if(flag) dfs(step+1);
		for(ll j=1;j<=f[b[step]][ans[step]].reactant[0];j++) 	vis[f[b[step]][ans[step]].reactant[j]]++;
	}
}
bool cmp(fc a,fc b)
{
	ll flag=1;
	for(ll i=1;i<=min(a.reactant[0],b.reactant[0]);i++)
	{
		if(a.reactant[i]==b.reactant[i]) continue;
		else if(a.reactant[i]>b.reactant[i]) return 0;
		else return 1; 
	}
	if(a.reactant[0]<b.reactant[0]) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(ll i=1;i<=m;i++) 
	{
		cin>>b[i];
		mp[b[i]]=1;
		f[b[i]][mp[b[i]]].reactant[0]=1;
		f[b[i]][mp[b[i]]].reactant[1]=b[i];
	}
	cin>>k;
	cin.get();
	while(k--)
	{
		getline(cin,s);
		//cout<<s<<"\n";
		ll flag=0,cnt=0,ff=0,tmp=0;
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='>') ff=1;
			if(!ff)
			{
				if(!flag&&'0'<=s[i]&&s[i]<='9') 
				{
					tmp=s[i]-'0';
					flag=1;
				}
				else if(flag&&'0'<=s[i]&&s[i]<='9') tmp=tmp*10+(s[i]-'0');
				else if(flag&&!('0'<=s[i]&&s[i]<='9')) 
				{
					flag=0;
					cnt++;
					p.reactant[cnt]=tmp;
				}	
			}
			else
			{
				if(!flag&&'0'<=s[i]&&s[i]<='9') 
				{
					tmp=s[i]-'0';
					flag=1;
				}
				else if(flag&&'0'<=s[i]&&s[i]<='9') 
				{
					tmp=tmp*10+(s[i]-'0');
					flag=0;
					mp[tmp]++;
					f[tmp][mp[tmp]].reactant[0]=cnt;
					for(ll ii=1;ii<=cnt;ii++) f[tmp][mp[tmp]].reactant[ii]=p.reactant[ii];
					f[tmp][0].reactant[0]=mp[tmp];
				}	
			}
		}
	}
	for(ll i=1;i<=m;i++)  sort(f[b[i]]+1,f[b[i]]+f[b[i]][0].reactant[0]+1,cmp);
	/*for(ll i=1;i<=m;i++)
	{
		cout<<b[i]<<"\n";
		for(ll j=1;j<=f[b[i]][0].reactant[0];j++)
		{
			for(ll k=1;k<=f[b[i]][j].reactant[0];k++) cout<<f[b[i]][j].reactant[k]<<" ";
			cout<<"\n"; 
		}
	}
	cout<<"-------------------------\n";*/
	for(ll i=1;i<=n;i++) vis[a[i]]=1;
	dfs(1);
	return 0;
}
