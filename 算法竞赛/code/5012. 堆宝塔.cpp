#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
deque<ll> dqa,dqb;
ll n,a[N],c,sum,maxnum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		c=a[i];
		if(dqa.empty())
		{
			dqa.push_back(i);
			continue;
		}
		if(a[dqa.back()]>c) 
		{
			dqa.push_back(i);
			continue;
		}
		if(dqb.empty())
		{
			dqb.push_back(i);
			continue;
		}
		if(a[dqb.back()]<c)
		{
			dqb.push_back(i);
			continue;
		}
		sum++;
		maxnum=max(maxnum,(ll)dqa.size());
		dqa.clear();
	    while(!dqb.empty())
	    {
	    	if(a[dqb.back()]<=c) break;
	    	dqa.push_back(dqb.back());
	    	dqb.pop_back();
		}
		dqa.push_back(i);
	}
	if(!dqa.empty()) sum++,maxnum=max(maxnum,(ll)dqa.size());
	if(!dqb.empty()) sum++,maxnum=max(maxnum,(ll)dqb.size());
	cout<<sum<<" "<<maxnum;
	return 0;
} 
