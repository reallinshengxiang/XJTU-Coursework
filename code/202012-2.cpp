#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct cj{
	ll y,result;
};
cj a[N];
ll maxx,ans,pos,last,m,pre[N],nex[N];
bool cmp(cj a,cj b)
{
	if(a.y<b.y) return 1;
	if(a.y==b.y&&a.result<b.result) return 1;
	return 0; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m;
	for(ll i=1;i<=m;i++) cin>>a[i].y>>a[i].result;
	sort(a+1,a+m+1,cmp);
//	cout<<"\n";
//	for(ll i=1;i<=m;i++) cout<<a[i].y<<"  "<<a[i].result<<"\n";
	last=a[1].y;
	for(ll i=1;i<=m;i++)
	{
		pre[i]=pre[i-1];
		if(a[i].y==last) continue;
		pos=i-1;
		while(a[pos].y==last&&pos>=1) 
		{
			if(a[pos].result==0) pre[i]++;	
			pos--;
		}
		last=a[i].y;	
	}
	for(ll i=m;i>=1;i--)
	{
		nex[i]=nex[i+1];
		if(a[i].result) nex[i]++;
	}
	maxx=-1;
	for(ll i=m;i>=1;i--)
	{
		if(nex[i]+pre[i]>maxx) 
		{
			maxx=nex[i]+pre[i];
			ans=a[i].y;
		}
	}
//	for(ll i=1;i<=m;i++) cout<<pre[i]<<"   "<<nex[i]<<"\n";
	cout<<ans;
	return 0;
}
