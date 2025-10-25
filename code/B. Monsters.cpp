#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
struct mst{
	ll num,id;
	bool operator<(const mst& m) const
	{
		if(m.num>num) return 1;
		if(m.num==num&&m.id<id) return 1;
		return 0;
	}
};
mst a[N],xx;
priority_queue<mst> q;
ll T,minn,x,n,k,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].num;
			a[i].id=i;
		}
		for(ll i=1;i<=n;i++)  
		{
			a[i].num=(a[i].num-1)%k+1;
			q.push(a[i]);
		}
		cnt=0;
		while(cnt<n)
		{
			xx=q.top();
			q.pop();
			xx.num=xx.num-k;
			if(xx.num<=0)
			{
				cnt++;
				cout<<xx.id<<" ";
			}
			else q.push(xx);
		}
		cout<<"\n";
	}
	return 0;
}
