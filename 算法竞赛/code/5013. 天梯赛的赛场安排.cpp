#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
struct sch{
	string name;
	ll num,jk,id;
};
sch a[N];
ll sum,n,c,kw[N];
bool cmp(sch x,sch y)
{
	if(x.num>y.num) return 1;
	return 0;
}
bool cmp2(sch x,sch y)
{
	if(x.id<y.id) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].num;
		a[i].id=i;
		a[i].jk=a[i].num/c;
		a[i].num=a[i].num%c;
		sum=sum+a[i].jk;
	}
	sort(a+1,a+n+1,cmp);
	ll cnt=0;
	for(ll i=1;i<=n;i++)
	{
		if(a[i].num==0) break;
		ll flag=0;
		for(ll j=1;j<=cnt;j++)
		{
			if(a[i].num<=kw[j]) 
			{
				kw[j]=kw[j]-a[i].num;
				a[i].jk++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cnt++;
			kw[cnt]=c-a[i].num;
			a[i].jk++;
			sum++;
		}
	}
	sort(a+1,a+n+1,cmp2);
	for(ll i=1;i<=n;i++) cout<<a[i].name<<" "<<a[i].jk<<"\n";
	cout<<sum;
	return 0;
} 
