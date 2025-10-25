#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m,T,a[N],b[N],st,ed,stt,edd,ans,f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=m;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		st=0,ed=n+1;
		stt=1,edd=m;
		f=-1;
		ans=0;
		while(st+1<ed)
		{
			if(f==1)
			{
				f=-f;
				st++;
				if(abs(a[st]-b[stt])>=abs(a[st]-b[edd])) ans=ans+abs(a[st]-b[stt]),stt++;
				else ans=ans+abs(a[st]-b[edd]),edd--;
			}
			else
			{
				f=-f;
				ed--;
				if(abs(a[ed]-b[stt])>abs(a[ed]-b[edd])) ans=ans+abs(a[ed]-b[stt]),stt++;
				else ans=ans+abs(a[ed]-b[edd]),edd--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
