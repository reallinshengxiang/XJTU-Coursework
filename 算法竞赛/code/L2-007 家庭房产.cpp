#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#pragma GCC optimize(2)
const ll N=1e5+10;
struct peo{
	ll id,k,num;
	ld ss;
};
peo p[N];
struct ans{
	ll minn,peo_sum,num_sum;
	ld ss_sum,num_ave,ss_ave;
};
ans a[N];
map<ll,ll> mp;
vector<ll> e[N];
ll n,pos,vis[N],cnt,nn;
void zh(ll x)
{
	if(x/1000!=0) cout<<x;
	else if(x/100!=0) cout<<"0"<<x;
	else if(x/10!=0) cout<<"00"<<x;
	else cout<<"000"<<x;
}
void bfs(ll now)
{
	vis[now]=1;
	deque<ll> dq;
	dq.push_back(now);
	nn++;
	a[nn].minn=p[now].id;
	a[nn].num_sum=p[now].num;
	a[nn].peo_sum=1;
	a[nn].ss_sum=p[now].ss;
	while(!dq.empty())
	{
		ll x=dq.front();
		dq.pop_front();
		for(ll i=0;i<e[x].size();i++)
		{
			ll y=e[x][i];
			if(vis[y]) continue;
			vis[y]=1;
			a[nn].minn=min(a[nn].minn,p[y].id);
			a[nn].num_sum=a[nn].num_sum+p[y].num;
			a[nn].ss_sum=a[nn].ss_sum+p[y].ss;
			a[nn].peo_sum++;
			dq.push_back(y);
		}
	}
} 
bool cmp(ans x,ans y)
{
	if(x.ss_ave>y.ss_ave) return 1;
	if(x.ss_ave==y.ss_ave&&x.minn<y.minn) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		if(!mp[x]) 
		{
			cnt++;
			mp[x]=cnt;
		}
		p[mp[x]].id=x;
		pos=mp[x];
		for(ll j=1;j<=2;j++)
		{
			cin>>x;
			if(x==-1) continue;
			if(!mp[x]) 
			{
				cnt++;
				mp[x]=cnt;
			}
			p[mp[x]].id=x;
			e[mp[x]].push_back(pos);
			e[pos].push_back(mp[x]);
		}
		cin>>p[pos].k;
		for(ll j=1;j<=p[pos].k;j++)
		{
			cin>>x;
			if(!mp[x]) 
			{
				cnt++;
				mp[x]=cnt;
			}
			p[mp[x]].id=x;
			e[pos].push_back(mp[x]);
			e[mp[x]].push_back(pos);
		}
		cin>>p[pos].num>>p[pos].ss;
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(!vis[i]) bfs(i);
	}
	for(ll i=1;i<=nn;i++) 
	{
		a[i].num_ave=(ld)(a[i].num_sum*1.0/a[i].peo_sum);
		a[i].ss_ave=(ld)(a[i].ss_sum*1.0/a[i].peo_sum);
	}
	sort(a+1,a+nn+1,cmp);
	cout<<nn<<"\n";
	for(ll i=1;i<=nn;i++)
	{
		zh(a[i].minn);
		cout<<" "<<a[i].peo_sum<<" "<<fixed<<setprecision(3)<<a[i].num_ave<<" "<<a[i].ss_ave<<"\n";
	}
	return 0;
 } 
