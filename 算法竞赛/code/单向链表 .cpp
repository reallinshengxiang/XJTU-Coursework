#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct node{
	ll data,next;
};
node a[N];
map<ll,ll> mp;
ll q,cnt,pos,x,y,opt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>q;
	cnt++;
	a[cnt].data=1;
	a[cnt].next=-1;
	mp[1]=cnt;
	while(q--)
	{
		cin>>opt>>x;
		if(opt==1)
		{
			cin>>y;
			pos=mp[x];
			cnt++;
			a[cnt].data=y;
			a[cnt].next=a[pos].next;
			a[pos].next=cnt;
			mp[y]=cnt;
		}
		else if(opt==2)
		{
			pos=mp[x];
			if(a[pos].next==-1) cout<<"0\n";
			else cout<<a[a[pos].next].data<<"\n";
		}
		else if(opt==3)
		{
			pos=mp[x];
			if(a[pos].next==-1) continue;
			a[pos].next=a[a[pos].next].next;
		}
	}
	
	return 0;
}
