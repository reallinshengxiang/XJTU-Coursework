#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
ll n,opt,k,minn;
struct Tree{
	ll idx=0;
	ll num=0;
	struct node{
		ll x,tim;
		bool operator<(node y) const
		{
			if(x!=y.x) return x<y.x;
			else return tim<y.tim;
		}
	};
	tree<node,null_type,less<node>,rb_tree_tag,tree_order_statistics_node_update> tt,pp;
	void insert(ll x)
	{
		idx++;
		num++;
		tt.insert({x,idx});
	}
	void erase(ll x){
		ll rank=tt.order_of_key({x,0});
		auto it=tt.find_by_order(rank);
		tt.erase(it);
		num--;
	}
	ll getrank(ll x)
	{
		return tt.order_of_key({x,0})+1;
	}
	ll getbyrank(ll x){
		return (*tt.find_by_order(x-1)).x;
	}
	ll getpre(ll x){
		ll rank=tt.order_of_key({x,0});
		return (*tt.find_by_order(rank-1)).x;
	}
	ll getnex(ll x){
		ll rank=tt.order_of_key({x+1,0});
		return (*tt.find_by_order(rank)).x;
	}
	void add(ll x)
	{
		for(ll rank=num;rank>=1;rank--)
		{
			ll y=getbyrank(rank);
			y=y+x;
		}
	}
};
Tree tr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>minn;
	while(n--)
	{
		char ch;
		cin>>opt>>k;
		if(ch=='I') 
		{
			if(k>=minn) tr.insert(k);
		}
		else if(ch=='A') tr.add(k);
		//else if(ch=='S')
		else if(ch=='F') 
		{
			if(k>tr.num) cout<<"-1\n";
			else cout<<tr.getrank(k)<<"\n";
		}
	}
	return 0;
}
