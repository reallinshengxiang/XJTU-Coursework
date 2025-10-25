#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=2e5+10;
ll T,n,x,a,b,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		a=b=inf;
		for(ll i=1;i<=n;i++)
		{
			cin>>x;
			if(b>=x) b=x;
			else if(a>=x) a=x;
			else 
			{
				ans++;
				b=a;
				a=x;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
