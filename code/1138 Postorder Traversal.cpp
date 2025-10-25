#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e4+10;
struct node{
	ll val,left_id,right_id;
};
node t[N];
ll cnt,p[N],pp,n,preorder[N],inorder[N];
ll build_tree(ll prest,ll preed,ll inst,ll ined)
{
	if(prest<1||preed>n||prest>preed||inst<1||ined>n||inst>ined) return -1;
	cnt++;
	t[cnt].val=preorder[prest];
	ll tmp=cnt,pos=p[t[cnt].val];
	t[tmp].left_id=build_tree(prest+1,prest+pos-inst,inst,pos-1);
	t[tmp].right_id=build_tree(prest+pos-inst+1,preed,pos+1,ined);
	return tmp;
}
void print(ll x)
{
	if(t[x].left_id!=-1) print(t[x].left_id);
	if(t[x].right_id!=-1) print(t[x].right_id);
	cout<<t[x].val;
	pp++;
	if(pp==1) exit(0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>preorder[i];
	for(ll i=1;i<=n;i++) cin>>inorder[i],p[inorder[i]]=i;
	ll root=build_tree(1,n,1,n);
	//for(ll i=1;i<=n;i++) cout<<i<<"  "<<t[i].val<<"   "<<t[i].left_id<<"    "<<t[i].right_id<<"\n";
	print(root);
	return 0;
}
