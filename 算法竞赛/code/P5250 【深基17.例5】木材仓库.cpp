#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll cnt,root,num,n,opt,len;
unordered_map<ll,ll> mp;
struct node{
	ll ls,rs,key,pri,size;
};
node t[N];
void newnode(ll x)
{
	cnt++;
	t[cnt].size=1;
	t[cnt].ls=t[cnt].rs=0;
	t[cnt].key=x;
	t[cnt].pri=rand();
}
void update(ll u)
{
	t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
void split(ll u,ll x,ll &l,ll &r)
{
	if(u==0) {l=r=0; return;}
	if(t[u].key<=x)
	{
		l=u;
		split(t[u].rs,x,t[u].rs,r);
	}
	else
	{
		r=u;
		split(t[u].ls,x,l,t[u].ls);
	}
	update(u);
}
ll merge(ll l,ll r)
{
	if(l==0||r==0) return l+r;
	if(t[l].pri>t[r].pri)
	{
		t[l].rs=merge(t[l].rs,r);
		update(l);
		return l;
	}
	else
	{
		t[r].ls=merge(l,t[r].ls);
		update(r);
		return r;
	}
}
void insert(ll x)
{
	ll l,r;
	split(root,x,l,r);
	newnode(x);
	ll aa=merge(l,cnt);
	root=merge(aa,r);
}
ll del(ll x)
{
	ll l,r,p;
	split(root,x,l,r);
	split(l,x-1,l,p);
	p=merge(t[p].ls,t[p].rs);
	root=merge(merge(l,p),r);
}
ll rak(ll x)
{
	ll l,r,ans;
	split(root,x-1,l,r);
	ans=t[l].size+1;
	root=merge(l,r);
	return ans;
}
ll kth(ll u,ll k)
{
	if(k==t[t[u].ls].size+1) return u;
	if(k<=t[t[u].ls].size) return kth(t[u].ls,k);
	if(k>t[t[u].ls].size) return kth(t[u].rs,k-1-t[t[u].ls].size);
}
ll pre(ll x)
{
	ll l,r,ans;
	split(root,x-1,l,r);
	ans=t[kth(l,t[l].size)].key;
	root=merge(l,r);
	return ans;
}
ll suc(ll x)
{
	ll l,r,ans;
	split(root,x,l,r);
	ans=t[kth(r,1)].key;
	root=merge(l,r);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>opt>>len;
		if(opt==1)
		{
			if(mp[len]==1) cout<<"Already Exist\n";
			else 
			{
				insert(len);
				mp[len]=1;
				num++;
			}
		}
		else
		{
			if(mp[len]==1) 
			{
				del(len);
				num--;
				mp[len]=0;
				cout<<len<<"\n";
			}
			else if(num==0) cout<<"Empty\n";
			else
			{
				ll x1,x2,pos;
				insert(len);
				pos=rak(len);
				if(pos==1) 
				{
					x2=suc(len);
					del(x2);
					mp[x2]=0;
					num--;
					cout<<x2<<"\n";
				}
				else if(pos==num+1) 
				{
					x1=pre(len);
					del(x1);
					mp[x1]=0;
					num--;
					cout<<x1<<"\n";
				}
				else
				{
					num--;
					x1=pre(len);
					x2=suc(len);
					if(abs(x1-len)>abs(x2-len))
					{
					    del(x2);
					    mp[x2]=0;
					    cout<<x2<<"\n";
					}
					else
					{
					    del(x1);
					    mp[x1]=0;
					    cout<<x1<<"\n";
					}
				}
				del(len);
			}
		}
	}
	return 0;
}
