#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=55;
ll ans,n,m,ww,bb,rr,w[N],b[N],r[N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	ans=n*m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		ww=bb=rr=0;
		for(ll j=0;j<=m-1;j++) 
		{
			if(s[j]=='W') ww++;
			else if(s[j]=='B') bb++;
			else if(s[j]=='R') rr++;
		}
		w[i]=w[i-1]+m-ww;
		b[i]=b[i-1]+m-bb;
		r[i]=r[i-1]+m-rr;
	}
	for(ll len=1;len<=n-2;len++)
	{
		for(ll i=1;i+len<=n-1;i++) ans=min(ans,w[i]+b[i+len]-b[i]+r[n]-r[i+len]);
	}
	cout<<ans;
	return 0;
}
