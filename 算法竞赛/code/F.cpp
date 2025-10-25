#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200020],n,x,k;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ll cnt=0;
	while(n--)
	{
		cin>>s;
		if(s[0]=='A')
		{
			cnt++;
			cin>>x;
			a[cnt]=x;
		}
		else if(s[0]=='D')
		{
			cin>>x;
			for(ll i=1;i<=cnt;i++) 
			{
				if(a[i]==x)
				{
					k=i;
					break;
				}
			}
			a[k]=a[cnt];
			cnt--;
		}
		else
		{
			sort(a+1,a+cnt+1);
			ll ans=0x7f;
		    for(ll i=1;i<=cnt-1;i++)	
			{
				for(ll j=i+1;j<=cnt;j++) ans=min(ans,a[i]^a[j]);
			}
			cout<<ans<<"\n"; 
		}
	}
	return 0;
}
