#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf long double
const ll N=1e5+10;
struct shu{
	ll x;
	double w;
};
shu a[N];
ll n;
bool cmp(shu a,shu b)
{
	if(a.x!=b.x) return a.x<b.x;
	return a.w<b.w;
}
ll search(ll st,ll ed,lf k)
{
	if(ed-st+1<5)
	{
		sort(a+st,a+ed+1,cmp);
		lf sum=0;
		for(ll i=st;i<=ed;i++)
		{
			sum=sum+a[i].w;
			if(sum>k) return a[i].x;
		}
	}
	for(ll i=0;i<=(ed-st-4)/5;i++)
	{
		ll pl=st+5*i;
		ll pr=pl+4;
		sort(a+pl,a+pr+1,cmp);
		swap(a[st+i],a[pl+2]);
	}
	sort(a+st,a+st+(ed-st-4)/5+2,cmp);
	ll xx=a[st+(ed-st+6)/10].x;
	ll l=st,r=ed;
	while(l<r)
	{
		if(a[l].x<xx) l++;
		if(a[r].x>xx) r--;
		swap(a[l],a[r]);
	}
	ll pos=l;
	lf sum=0;
	for(ll i=st;i<=pos;i++)	sum=sum+a[i].w;
	if(sum>k) search(st,pos,k);
	else search(pos+1,ed,k-sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].x;
	for(ll i=1;i<=n;i++) cin>>a[i].w;
	cout<<search(1,n,0.5);
	return 0;
 } 
