#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct question{
	ll l,r,flag;
};
question a[N];
string ss;
ll n,m,b[N],s[N],cnt,num;
ll find_set(ll x)
{
	if(s[x]!=x) s[x]=find_set(s[x]);
	return s[x];
}
void merge(ll x,ll y)
{
	x=find_set(x);
	y=find_set(y);
	s[x]=y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=m;i++)
	{
		cin>>a[i].l>>a[i].r>>ss;
		a[i].l--;
		if(ss[0]=='o') a[i].flag=1;
		else a[i].flag=0;
		b[++cnt]=a[i].l;
		b[++cnt]=a[i].r;
	}
	sort(b+1,b+cnt+1);
	num=unique(b+1,b+cnt+1)-(b+1);
	for(ll i=1;i<=num*2;i++) s[i]=i;
	for(ll i=1;i<=m;i++)
	{
		a[i].l=lower_bound(b+1,b+num+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+num+1,a[i].r)-b;
		if(a[i].flag==0)
		{
			if(find_set(a[i].l)==find_set(a[i].r+num)) 
			{
				cout<<i-1;
				return 0;
			}
			else 
			{
				merge(a[i].l,a[i].r);
				merge(a[i].l+num,a[i].r+num);
			}
		}
		else
		{
			if(find_set(a[i].l)==find_set(a[i].r)) 
			{
				cout<<i-1;
				return 0;
			}
			else 
			{
				merge(a[i].l,a[i].r+num);
				merge(a[i].l+num,a[i].r);
			}
		}
	}
	cout<<m;
	return 0;
}
