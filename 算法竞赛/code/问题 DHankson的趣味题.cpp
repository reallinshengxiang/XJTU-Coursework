#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,p1,p2,a0,a1,b0,b1,ans,x,y,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>a0>>a1>>b0>>b1;
		p1=a0/a1;
		p2=b1/b0;
		ans=0;
		n=sqrt(b1);
		for(ll i=1;i<=n;i++)
		{
			x=i;
			if(b1%x==0)
			{
				if(x%a1==0&&__gcd(x/a1,p1)==1&&__gcd(p2,b1/x)==1)  ans++;
				ll y=b1/x;
				if(x==y) continue;
				x=y;
				if(x%a1==0&&__gcd(x/a1,p1)==1&&__gcd(p2,b1/x)==1)  ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
