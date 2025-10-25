#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans=0,ansx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=64;i++)
	{
		
		ll xx,x,sum=0;
		scanf("%lld",&x);
		cout<<i<<"   "<<x<<"\n";
		xx=x;
		while(xx!=0)
		{
			sum=sum+xx%10;
			xx=xx/10;
		}
		if(sum>ans)
		{
			ans=sum;
            ansx=x;
		}
	}
	cout<<ans<<" "<<ansx<<"\n";
	return 0;
}
