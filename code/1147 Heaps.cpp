#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e3+10;
struct node{
	ll val,left_id,right_id;
};
node t[N];
ll cnt,a[N],n,m;
void print(ll x)
{
	
	if(t[x].left_id!=-1) print(t[x].left_id);
	if(t[x].right_id!=-1) print(t[x].right_id);
	if(cnt!=m-1) cout<<t[x].val<<" ",cnt++;
	else cout<<t[x].val;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	while(n--)
	{
		for(ll i=1;i<=m;i++) cin>>a[i];
		for(ll i=1;i<=m;i++)
		{
			t[i].val=a[i];
			if(i*2<=m) t[i].left_id=i*2;
			else t[i].left_id=-1;
			if(i*2+1<=m) t[i].right_id=i*2+1;
			else t[i].right_id=-1;
		}
		ll flag,f=1;
		if(a[1]<a[2]) flag=1;
		else flag=0;
		for(ll i=1;i<=m;i++)
		{
			if(flag==1)
			{
				
				if(t[i].left_id!=-1&&t[t[i].left_id].val<t[i].val)
				{
					f=0;
					break;
				} 
				if(t[i].right_id!=-1&&t[t[i].right_id].val<t[i].val)
				{
					f=0;
					break;
				} 
			}
			else
			{
				if(t[i].left_id!=-1&&t[t[i].left_id].val>t[i].val)
				{
					f=0;
					break;
				} 
				if(t[i].right_id!=-1&&t[t[i].right_id].val>t[i].val)
				{
					f=0;
					break;
				} 
			}
		}
		if(!flag&&f) cout<<"Max Heap\n";
		else if(flag&&f) cout<<"Min Heap\n";
		else cout<<"Not Heap\n";
		cnt=0;
		print(1);
		if(n!=0) cout<<"\n";
	}
	return 0;
}
