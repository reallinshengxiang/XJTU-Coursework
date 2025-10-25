#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#pragma GCC optimize(2) 
const ll N=1e5+10;
struct node{
	ll val,left_id,right_id;
};
node t[N];
unordered_map<ll,ll> vis,visa;
ll n,m,inorder[N],preorder[N],cnt,p[N],root,fa[N],a[N],b[N];
ll find(ll x,ll prest,ll preed)
{
	ll l=prest,r=preed;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(preorder[mid]<=x) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
ll build_tree(ll prest,ll preed)
{
	if(prest<1||preed>n||prest>preed) return -1;
	cnt++;
	t[cnt].val=preorder[prest];
	ll pos=find(t[cnt].val,prest,preed);
	ll tmp=cnt;
	t[tmp].left_id=build_tree(prest+1,pos);
	t[tmp].right_id=build_tree(pos+1,preed);
	return tmp;
}
void find_lca(ll root,ll u,ll v)
{
	if(t[root].val>min(u,v)&&t[root].val<max(u,v)) cout<<"LCA of "<<u<<" and "<<v<<" is "<<t[root].val<<".";
    else if(t[root].val==min(u,v)&&t[root].val<max(u,v))  cout<<min(u,v)<<" is an ancestor of "<<max(u,v)<<".";
    else if(t[root].val==max(u,v)&&t[root].val>min(u,v))  cout<<max(u,v)<<" is an ancestor of "<<min(u,v)<<".";
    else if(t[root].val<min(u,v)) find_lca(t[root].right_id,u,v);
    else if(t[root].val>max(u,v)) find_lca(t[root].left_id,u,v);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=n;i++) cin>>preorder[i],vis[preorder[i]]=1;
	root=build_tree(1,n);
	fa[t[root].val]=-1;
	for(ll i=1;i<=cnt;i++) 
	{
		//cout<<i<<"  "<<t[i].val<<"  "<<t[i].left_id<<"   "<<t[i].right_id<<"\n";
		if(t[i].left_id!=-1) fa[t[t[i].left_id].val]=t[i].val;
		if(t[i].right_id!=-1) fa[t[t[i].right_id].val]=t[i].val;
	}
//	for(ll i=1;i<=n;i++) cout<<i<<"  "<<fa[i]<<"\n";
	while(m--)
	{
		ll u,v,lca;
		cin>>u>>v;
		if (!vis[u] && vis[v]) cout<< "ERROR: " <<u<< " is not found.";
        else if (!vis[u] && !vis[v]) cout<< "ERROR: " <<u<< " and " << v << " are not found.";
        else if (vis[u] && !vis[v]) cout<< "ERROR: " <<v<< " is not found.";
		else
		{
			if(u==v) cout<<u<<" is an ancestor of "<<v<<".";
			else find_lca(root,u,v);
		//	if(lca==u) 
		//	else if(lca==v) cout<<v<<" is an ancestor of "<<u<<".";
		//	else cout<<"LCA of "<<u<<" and "<<v<<" is "<<lca<<".";
		}
		cout<<"\n";
	}
	return 0;
} 
