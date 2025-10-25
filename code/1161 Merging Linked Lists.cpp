#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
struct node{
	ll data,next;
};
map<ll,node> mp;
node a[N];
ll f1,f2,n,l1[N],l2[N],ans[N];
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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>f1>>f2>>n;
	for(ll i=1;i<=n;i++)
	{
		ll address,data,next;
		cin>>address>>data>>next;
		mp[address].data=data;
		mp[address].next=next;
	}
	ll cnt1=0,cnt2=0,cnt=0;
	cnt1++;
	l1[cnt1]=f1;
	cnt2++;
	l2[cnt2]=f2; 
	while(1)
	{
		if(mp[l1[cnt1]].next==-1) break;
		cnt1++;
		l1[cnt1]=mp[l1[cnt1-1]].next;
		if(mp[l1[cnt1]].next==-1) break;
	}
//	cout<<"1111\n";
	while(1)
	{
		if(mp[l2[cnt2]].next==-1) break;
		cnt2++;
		l2[cnt2]=mp[l2[cnt2-1]].next;	
		if(mp[l2[cnt2]].next==-1) break;		
    }
//	cout<<cnt1<<"  "<<cnt2<<"\n";
	if(cnt1>=2*cnt2)
	{
		ll pos2=cnt2+1;
		for(ll pos1=1;pos1<=cnt1;pos1++)
		{
			cnt++;
			ans[cnt]=l1[pos1];
			if(pos1%2==0&&pos2>1)
			{
				cnt++;
				pos2--;
				ans[cnt]=l2[pos2];
			}
		}
	}
	else if(cnt2>=2*cnt1)
	{
		ll pos1=cnt1+1;
		for(ll pos2=1;pos2<=cnt2;pos2++)
		{
			cnt++;
			ans[cnt]=l2[pos2];
			if(pos2%2==0&&pos1>1)
			{
				cnt++;
				pos1--;
				ans[cnt]=l1[pos1];
			}
		}
	}
	for(ll i=1;i<=cnt;i++)
	{
		geshi(ans[i]);
		cout<<" "<<mp[ans[i]].data<<" ";
		if(i<cnt) geshi(ans[i+1]),cout<<"\n";
		else cout<<"-1";
	}
	return 0;
}
/*
00100 01000 6
02233 2 34891
00100 6 -1
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033*/
