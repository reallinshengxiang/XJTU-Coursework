#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct cow{
	ll maxx,minn;
};
cow niu[2550];
struct sunscreen{
	ll sun,num;
};
sunscreen ss[2550];
bool cmp1(cow a,cow b)
{
	return a.maxx<b.maxx;
}
bool cmp2(sunscreen a,sunscreen b)
{
	return a.sun<b.sun;
}
ll c,l,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>l;
	for(ll i=1;i<=c;i++) cin>>niu[i].minn>>niu[i].maxx;
	for(ll i=1;i<=l;i++) cin>>ss[i].sun>>ss[i].num;
	sort(niu+1,niu+c+1,cmp1);
	sort(ss+1,ss+l+1,cmp2);
	ans=0;
	for(ll i=1;i<=c;i++)
	{
		for(ll j=1;j<=l;j++)
		{
			if(ss[j].num&&ss[j].sun>=niu[i].minn&&ss[j].sun<=niu[i].maxx)
			{
				ss[j].num--;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
