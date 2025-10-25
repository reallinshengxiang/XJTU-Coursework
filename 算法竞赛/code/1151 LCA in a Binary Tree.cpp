#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#pragma GCC optimize(2) 
const ll N=1e4+10;
struct node{
	ll val,left_id,right_id;
};
node t[N];
unordered_map<ll,ll> vis,visa;
ll n,m,inorder[N],preorder[N],cnt,p[N],root,fa[N],a[N],b[N];
ll build_tree(ll inst,ll ined,ll prest,ll preed)
{
	if(inst<1||ined>n||inst>ined||prest<1||preed>n||prest>preed) return -1;
	cnt++;
	t[cnt].val=preorder[prest];
	ll pos=p[t[cnt].val];
	ll tmp=cnt;
	t[tmp].left_id=build_tree(inst,pos-1,prest+1,prest+pos-inst);
	t[tmp].right_id=build_tree(pos+1,ined,prest+pos-inst+1,preed);
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	for(ll i=1;i<=n;i++) cin>>inorder[i];
	for(ll i=1;i<=n;i++) cin>>preorder[i];
	for(ll i=1;i<=n;i++) p[inorder[i]]=i,vis[inorder[i]]=1;
	root=build_tree(1,n,1,n);
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
			ll aa=u,bb=v,cnt1=0,cnt2=0;
			visa.clear();
			while(1)
			{
				cnt1++;
				a[cnt1]=aa;
				visa[aa]=1;
				aa=fa[aa];
				if(aa==-1) break;
			}
			while(1)
			{
				cnt2++;
				b[cnt2]=bb;
				bb=fa[bb];
				if(bb==-1) break;
			}
			for(ll i=1;i<=cnt2;i++)
			{
				if(visa[b[i]])
				{
					lca=b[i];
					break;
				}
			}
			if(lca==u) cout<<u<<" is an ancestor of "<<v<<".";
			else if(lca==v) cout<<v<<" is an ancestor of "<<u<<".";
			else cout<<"LCA of "<<u<<" and "<<v<<" is "<<lca<<".";
		}
		cout<<"\n";
	}
	return 0;
} 
