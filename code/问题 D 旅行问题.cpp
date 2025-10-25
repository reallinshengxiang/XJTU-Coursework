#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
deque<ll> q;
ll flag[N],s[N],p[N],d[N],a[N],n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>p[i]>>d[i];
	d[0]=d[n];
	for(ll i=1;i<=n;i++) a[i]=a[i+n]=p[i]-d[i];
	for(ll i=1;i<=2*n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=2*n-1;i++)
	{
		while(!q.empty()&&i-n>=q.front()) q.pop_front();
		while(!q.empty()&&s[q.back()]>=s[i]) q.pop_back();
		q.push_back(i);
		if(i>=n&&s[q.front()]>=s[i-n]) flag[i-n+1]=1;
	}
	memset(s,0,sizeof(s));
	for(ll i=1;i<=n;i++) a[i]=a[i+n]=p[n-i+1]-d[n-i];
	for(ll i=1;i<=2*n;i++) s[i]=s[i-1]+a[i];
	for(ll i=1;i<=2*n-1;i++)
	{
		while(!q.empty()&&i-n>=q.front()) q.pop_front();
		while(!q.empty()&&s[q.back()]>=s[i]) q.pop_back();
		q.push_back(i);
		if(i>=n&&s[q.front()]>=s[i-n]) flag[2*n-i]=1;
	}
	for(ll i=1;i<=n;i++)
	{
		if(flag[i]) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;
} 
