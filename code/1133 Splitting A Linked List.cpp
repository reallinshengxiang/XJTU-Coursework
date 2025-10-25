#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
struct Address{
	ll data,next;
};
map<ll,Address> mp;
ll first,n,k,address,a[N],cnt,b[5][N];
void geshi(ll x)
{
	if(x<10) cout<<"0000"<<x;
	else if(x<100) cout<<"000"<<x;
	else if(x<1000) cout<<"00"<<x;
	else if(x<10000) cout<<"0"<<x;
	else cout<<x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>first>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		ll data,nex;
		cin>>address>>data>>nex;
		mp[address].data=data;
		mp[address].next=nex;
	} 
	address=first;
	for(ll i=1;i<=n;i++)
	{
		a[i]=address;
		cnt=i;
		address=mp[address].next;
		if(address==-1) break;
	}
	ll cnt1=0,cnt2=0,cnt3=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(mp[a[i]].data<0)
		{
			cnt1++;
			b[1][cnt1]=a[i];
		}
		else if(0<=mp[a[i]].data&&mp[a[i]].data<=k) 
		{
			cnt2++;
			b[2][cnt2]=a[i];
		}
		else if(mp[a[i]].data>k)
		{
			cnt3++;
			b[3][cnt3]=a[i];
		}
	}
	ll cnt=0;
	for(ll i=1;i<=cnt1;i++)
	{
		cnt++;
		a[cnt]=b[1][i];
	}
	for(ll i=1;i<=cnt2;i++)
	{
		cnt++;
		a[cnt]=b[2][i];
	}
	for(ll i=1;i<=cnt3;i++)
	{
		cnt++;
		a[cnt]=b[3][i];
	}
	for(ll i=1;i<=cnt;i++)
	{
		geshi(a[i]);
		cout<<" "<<mp[a[i]].data<<" ";
		if(i!=cnt) 
		{
			geshi(a[i+1]);
			cout<<"\n";
		}
		else cout<<"-1";
	}
	return 0;
}
