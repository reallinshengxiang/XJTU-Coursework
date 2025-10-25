#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1,ans2,ans,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=10;i<=100000000;i++)
	{
		ll t=i;
		ll tt=i;
		cnt=0;
		while(t!=0)
		{
			t=t/10;
			cnt++;
		}
		if(cnt%2==0)
		{
			ans1=ans2=0;
			for(ll j=1;j<=cnt/2;j++)
			{			
				ans1=ans1+tt%10;
				tt=tt/10;
			}
			for(ll j=1;j<=cnt/2;j++)
			{			
				ans2=ans2+tt%10;
				tt=tt/10;
			}
			if(ans1==ans2) 
		    {
		    ans++;	
		    }
		}
	}
	cout<<ans<<"\n";
	return 0;
}
