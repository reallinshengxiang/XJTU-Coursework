#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct stone{
	ll a,b,id;
};
stone s1[100010],s2[100010];
ll T,n;
bool cmp1(stone x,stone y)
{
	return x.a>y.a;
}
bool cmp2(stone x,stone y)
{
	return x.b>y.b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		map<ll,ll> mp;
		for(ll i=1;i<=n;i++)
		{
			cin>>s1[i].a>>s1[i].b;
			s1[i].id=i;
			s2[i]=s1[i];
		}
		sort(s1+1,s1+n+1,cmp1);
		sort(s2+1,s2+n+1,cmp2);
		ll num=1,t1=1,t2=1,ans1=0,ans2=0;
		while(num<=n)
		{
			if(num%2) 
			{
				while(mp[s1[t1].id]) t1++;
				mp[s1[t1].id]=1;
				ans1=ans1+s1[t1].a;
			}
			else
			{
				while(mp[s2[t2].id]) t2++;
				mp[s2[t2].id]=1;
				ans2=ans2+s2[t1].b;
			}
			num++;
		}
		cout<<ans1-ans2<<"\n";
	}
	return 0;
}
