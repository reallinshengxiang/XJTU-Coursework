#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll m[N],flag,sum,n,f,a,b,T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>f>>a>>b;
		for(ll i=1;i<=n;i++) cin>>m[i];
		sum=f;
		flag=0;
		for(ll i=1;i<=n;i++)
		{
			sum=max(sum-(m[i]-m[i-1])*a,sum-b);
			if(sum<=0)
			{
				flag=1;
				break;
			}
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
