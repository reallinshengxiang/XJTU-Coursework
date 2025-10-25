#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct rizhi{
	ll id,ts;
};
rizhi r[N];
bool cmp(rizhi a,rizhi b)
{
	if(a.id<b.id) return 1;
	if(a.id==b.id&&a.ts<b.ts) return 1;
	return 0;
}
deque<ll> dq;
ll p[N],n,d,k,pos,cnt;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d>>k;
	for(ll i=1;i<=n;i++) cin>>r[i].ts>>r[i].id;
	sort(r+1,r+n+1,cmp);
	pos=0;
	for(ll i=1;i<=n;i++)
	{
		if(!mp[r[i].id])
		{
			mp[r[i].id]=1;
			p[++cnt]=i;
		}
	}
	p[cnt+1]=n+1;
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=p[i];j<=p[i+1]-1;j++)
		{
			if(j==p[i])
			{
				pos=r[j].id;
				dq.clear();
			}
			while(!dq.empty()&&r[dq.front()].ts+d<=r[j].ts) dq.pop_front();
	     	dq.push_back(j);
		    if(dq.size()>=k)
		    {
			    cout<<pos<<"\n";
			    break;
		    }
		}		
	}
	return 0;
}
