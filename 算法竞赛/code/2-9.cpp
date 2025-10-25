#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll a[N],n,k;
map<ll,ll> mp;                        //记录每个数出现次数 
ll find_kth(ll st,ll ed,ll k)         //线性时间算法找出第k(0,1,2……）大的数 
{
	if(ed-st<=75)
	{
		sort(a+st,a+ed);
		return a[st+k];
	}
	ll len2=(ed-st+4),pos=st;
	for(ll i=st;i<=ed-1;i=i+5)
	{
		ll e1=i+5;
		if(e1>ed) e1=ed;
		sort(a+i,a+e1);
		ll id=(e1-i-1)/2,s=a[i+id];
		a[i+id]=a[pos];
		a[pos]=s;
		pos++;
	}
	ll val=find_kth(st,pos,(st+pos)/2-st);
	ll p1=st,p2=ed,p3=ed;
	while(p1<p2)
	{
		if(a[p1]<val)	p1++;
		else
		{
			p2--;
			swap(a[p1],a[p2]);
		}
	}
	while(p2<p3)
	{
		if(a[p2]==val) p2++;
		else
		{
			p3--;
			swap(a[p2],a[p3]);
		}
	}
	if(st+k>=p1)
	{
		if(st+k>=p2)  return find_kth(p2,ed,k-(p2-st));
		else return val;
	}
	else return find_kth(st,p1,k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=0;i<=n-1;i++) cin>>a[i],mp[a[i]]++;
	if(mp[find_kth(0,n,n/2)]>=n/2+1) cout<<"YES";   //存在主元素 
	else cout<<"NO";                                //不存在主元素 
	return 0;
}


