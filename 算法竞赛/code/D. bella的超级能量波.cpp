#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct wave{
	ll st,ed,flag;
};
wave a[200010];
bool cmp(wave xx,wave yy)
{
	return xx.st<yy.st;
}
ll ans,last,n,m,x,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++) cin>>a[i].st>>a[i].ed;
	sort(a+1,a+m+1,cmp);
	last=1;
	for(ll i=1;i<=m;i++)
	{
		x=last;
		cnt=i;
		while(a[cnt].st<=last&&cnt<=m)  
		{
			x=max(x,a[cnt].ed);
			cnt++;
		}
		last=x+1;
		ans++;
		if(last>n) break;
		i=cnt-1;		
	}
	cout<<ans;
	return 0;
}
