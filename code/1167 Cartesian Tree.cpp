#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=50;
struct tree{
	ll val,left_id,right_id;
};
tree t[N];
ll n,a[N],cnt,root;
vector<ll> e[N];
deque<tree> dq;
ll find_minid(ll st,ll ed)
{
	ll minn=a[st],ans=st;
	for(ll i=st;i<=ed;i++)
	{
		if(a[i]<minn) minn=a[i],ans=i;
	}
	return ans;
}
ll build_tree(ll st,ll ed)
{
	if(st<1||ed>n||st>ed) return -1;
	cnt++;
	ll pos=find_minid(st,ed);
	t[cnt].val=a[pos];
	ll tmp=cnt;
	t[tmp].left_id=build_tree(st,pos-1);
	t[tmp].right_id=build_tree(pos+1,ed);
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	root=build_tree(1,n);
	//for(ll i=1;i<=cnt;i++) cout<<t[i].val<<"  "<<t[i].left_id<<" "<<t[i].right_id<<"\n";
	dq.push_back(t[root]);
	ll sum=0;
	while(!dq.empty())
	{
		tree p=dq.front();
		dq.pop_front();
		cout<<p.val;
		sum++;
		if(sum<n) cout<<" ";
		if(p.left_id!=-1) dq.push_back(t[p.left_id]);
		if(p.right_id!=-1) dq.push_back(t[p.right_id]);
	}
	return 0;
}
