#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=110;
struct node{
	ll val,left_id,right_id,color;
};
node t[N];
ll cnt,pp,n,preorder[N],inorder[N],k,sum[N],qq;
map<ll,ll> c,p;
ll build_tree(ll prest,ll preed,ll inst,ll ined)
{
	if(prest<1||preed>n||prest>preed||inst<1||ined>n||inst>ined) return -1;
	cnt++;
	t[cnt].val=preorder[prest];
	t[cnt].color=c[t[cnt].val];
	ll tmp=cnt,pos=p[t[cnt].val];
	t[tmp].left_id=build_tree(prest+1,prest+pos-inst,inst,pos-1);
	t[tmp].right_id=build_tree(prest+pos-inst+1,preed,pos+1,ined);
	return tmp;
}
ll to_ll(string ss)
{
	ll ans=0;
	if(ss[0]=='-')
	{
		for(ll i=1;i<ss.size();i++) ans=ans*10+(ss[i]-'0');
	}
	else for(ll i=0;i<ss.size();i++) ans=ans*10+(ss[i]-'0');
	return ans;
}
void dfs(ll id,ll num)
{
	if(t[id].color==0) num++;
	if(t[id].left_id==-1&&t[id].right_id==-1)
	{
		qq++;
		sum[qq]=num;
	}
	if(t[id].left_id!=-1)
	{
		dfs(t[id].left_id,num);
	}
	if(t[id].right_id!=-1) 
	{
		dfs(t[id].right_id,num);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>k;
	while(k--)
	{
		cin>>n;
		c.clear();
		p.clear();
		cnt=qq=0;
		for(ll i=1;i<=n;i++) 
		{
			string ss;
			cin>>ss;
			preorder[i]=to_ll(ss);
			if(ss[0]=='-') c[preorder[i]]=1;
			else c[preorder[i]]=0;
			inorder[i]=preorder[i];
		}
		sort(inorder+1,inorder+n+1);
		for(ll i=1;i<=n;i++) p[inorder[i]]=i;
		ll root=build_tree(1,n,1,n);
		ll flag=1;
		if(t[root].color==1) flag=0;
		for(ll i=1;i<=cnt;i++) 
		{
			//cout<<i<<"  "<<t[i].val<<"  "<<t[i].left_id<<"  "<<t[i].right_id<<"  "<<t[i].color<<"\n";
			if(t[i].left_id!=-1)
			{
				if(t[i].color==1&&t[t[i].left_id].color!=0)
				{
					flag=0;
					break;
				}
			} 
			if(t[i].right_id!=-1)
			{
				if(t[i].color==1&&t[t[i].right_id].color!=0)
				{
					flag=0;
					break;
				}
			} 
		}
		dfs(root,0);
		for(ll i=2;i<=qq;i++) 
		{
			if(sum[i]!=sum[i-1]) flag=0;
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";		
	}

	return 0;
}
