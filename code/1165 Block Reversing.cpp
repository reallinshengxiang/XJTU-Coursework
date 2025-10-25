#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct node{
	ll val,next;
};
ll a[N],cnt,x,y,z,first,n,k;
map<ll,node> mp;
map<ll,ll> pos;
void geshi(ll x)
{
	if(x<=9) cout<<"0000"<<x;
	else if(x<=99) cout<<"000"<<x;
	else if(x<=999) cout<<"00"<<x;
	else if(x<=9999) cout<<"0"<<x;
	else cout<<x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>first>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		mp[x].val=y;
		mp[x].next=z;
		pos[y]=x;
	}
	cnt++;
	a[cnt]=first;
	while(1)
	{
		x=a[cnt];
		y=mp[x].next;
		if(y==-1) break;
		cnt++;
		a[cnt]=y;
	}
//	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	for(ll i=(n-1)/k*k+1;i>=1;i=i-k)
	{
		ll st=i;
		ll ed=min(n,i+k-1);
	//	cout<<st<<"   "<<ed<<"\n";
		for(ll j=st;j<=ed;j++)
		{
			geshi(pos[mp[a[j]].val]);
			cout<<" "<<mp[a[j]].val<<" ";
			if(j!=k&&j!=ed) 
			{
				geshi(pos[mp[a[j+1]].val]);
				cout<<"\n";
			}
			else if(j!=k&&j==ed)
			{
				geshi(pos[mp[a[st-k]].val]);
				cout<<"\n";
			}
			else cout<<"-1";
		}
	}
	return 0;
}
