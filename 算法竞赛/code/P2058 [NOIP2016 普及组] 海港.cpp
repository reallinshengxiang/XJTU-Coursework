#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll tail,head,n,t,k,tt[N],num[N],x[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>t>>k;
		for(ll j=1;j<=k;j++)
		{
			tail++;
			tt[tail]=t;
			cin>>x[tail];
			if(!num[x[tail]]) ans++;
			num[x[tail]]++;
		}
		while(t-tt[head]>=86400)
		{
			if(num[x[head]]==1) ans--;
			num[x[head]]--;
			head++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
