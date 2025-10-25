#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
struct node{
	ll num,left=-1,right=-1;
};
node tree[N];
unordered_map<ll,ll> mp;
ll cnt,in[N],pre[N],n,ans[N];
deque<ll> q;
ll buildtree(ll inst,ll ined,ll prest,ll preed)
{
//	cout<<inst<<"   "<<ined<<"   "<<prest<<"    "<<preed<<"  "<<pre[prest]<<"\n";
	if(prest>preed||inst>ined) return -1;
	cnt++;
	ll cnt1=cnt;
	tree[cnt1].num=pre[prest];
	ll pos=mp[tree[cnt1].num];
	tree[cnt1].left=buildtree(inst,pos-1,prest+1,prest+pos-inst);
	tree[cnt1].right=buildtree(pos+1,ined,prest+pos-inst+1,preed);
//	cout<<tree[cnt].num<<"  "<<tree[cnt].left<<"   "<<tree[cnt].right<<"\n";
	return cnt1;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>in[i];
	for(ll i=1;i<=n;i++) cin>>pre[i];
	for(ll i=1;i<=n;i++) mp[in[i]]=i;
	ll root=buildtree(1,n,1,n);
	//for(ll i=1;i<=n;i++) cout<<tree[i].num<<"   "<<tree[i].left<<"   "<<tree[i].right<<"\n";
    cnt=0;
	q.push_back(root);
	ll nn=0;
	while(!q.empty())
	{
		ll len=q.size();
		//cout<<len<<"\n";
		for(ll i=1;i<=len;i++)
		{
			ll x=q.front();
			if(i==1)
			{
				cnt++;
				ans[cnt]=tree[x].num;
			}
		    q.pop_front();
		    if(tree[x].left!=-1) q.push_back(tree[x].left);
		    if(tree[x].right!=-1) q.push_back(tree[x].right);
		}
	}
	for(ll i=1;i<=cnt-1;i++) cout<<ans[i]<<" ";
	cout<<ans[cnt];
	return 0; 
}
