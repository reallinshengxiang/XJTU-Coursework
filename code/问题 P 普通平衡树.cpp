#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
ll n,opt,x;
struct Tree{
	ll idx=0;
	struct node{
		ll x,tim;
		bool operator<(node y) const
		{
			if(x!=y.x) return x<y.x;
			else return tim<y.tim;
		}
	};
	tree<node,null_type,less<node>,rb_tree_tag,tree_order_statistics_node_update> tt;
	void insert(ll x)
	{
		idx++;
		tt.insert({x,idx});
	}
	void erase(ll x){
		ll rank=tt.order_of_key({x,0});
		auto it=tt.find_by_order(rank);
		tt.erase(it);
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
};
Tree tr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>opt>>x;
		if(opt==1) tr.insert(x);
		else if(opt==2) tr.erase(x);
		else if(opt==3) cout<<tr.getrank(x)<<"\n";
		else if(opt==4) cout<<tr.getbyrank(x)<<"\n";
		else if(opt==5) cout<<tr.getpre(x)<<"\n";
		else if(opt==6) cout<<tr.getnex(x)<<"\n";
	}
	return 0;
}
