#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1010;
ll e[N][N],b[N],call_back[N],short_call[N],cnt,k,n,m,s[N],vis[N];
vector<ll> ee[N];
ll find_set(ll x)
{
	if(x!=s[x]) return s[x]=find_set(s[x]);
	return s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		ll caller,receiver,duration;
		cin>>caller>>receiver>>duration;
		e[caller][receiver]+=duration;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(e[i][j]>0&&e[i][j]<=5) 
			{
				short_call[i]++; 
				if(e[j][i]>0) call_back[i]++;
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(short_call[i]>k&&short_call[i]>=5*call_back[i])
		{
			cnt++;
			b[cnt]=i;
		}
	}
	if(cnt==0)
	{
		cout<<"None";
		return 0;
	}
	for(ll i=1;i<=n;i++) s[i]=i;
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=i+1;j<=cnt;j++)
		{
			if(e[b[i]][b[j]]&&e[b[j]][b[i]]) 
			{
				ll x=find_set(b[i]);
				ll y=find_set(b[j]);
				s[x]=y;
			}
		}
	}
	for(ll i=1;i<=n;i++) s[i]=find_set(s[i]);
	ll num=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(!vis[b[i]])
		{
			num++;
			ee[num].push_back(b[i]);
			vis[b[i]]=1;
			ll pos=i+1;
			while(pos<=cnt)
			{
				if(vis[b[pos]]==0&&s[b[pos]]==s[b[i]])
				{
					ee[num].push_back(b[pos]);
					vis[b[pos]]=1;
			    }
				pos++;
			}
	    }   
	}
	for(ll i=1;i<=num;i++)
	{
		for(ll j=0;j<ee[i].size();j++)
		{
			cout<<ee[i][j];
			if(j!=ee[i].size()-1) cout<<" ";
		}
		if(i!=num) cout<<"\n";
	} 
	return 0;
}
