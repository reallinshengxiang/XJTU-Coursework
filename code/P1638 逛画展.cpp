#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll a[N],num[N],ans,n,m,sum,st;
deque<ll> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
    ans=n;
	for(ll i=1;i<=n;i++)
	{
		if(num[a[i]]==0) sum++;
		q.push_back(i);
		num[a[i]]++;
		while(num[a[q.front()]]>=2&&!q.empty()) num[a[q.front()]]--,q.pop_front();
		if(sum==m) 
		{
			if(ans>q.back()-q.front()+1)
			{
				st=q.front();
				ans=q.back()-q.front()+1;
			}
		}
	}
	cout<<st<<" "<<st+ans-1;
	return 0;
}
