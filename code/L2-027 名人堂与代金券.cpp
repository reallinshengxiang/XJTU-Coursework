#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
struct stu{
	string name;
	ll fs;
};
stu a[N];
ll n,g,k,num,sum;
bool cmp(stu x,stu y)
{
	if(x.fs>y.fs) return 1;
	if(x.fs==y.fs&&x.name<y.name) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>g>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].fs;
		if(a[i].fs>=g) sum=sum+50;
		else if(a[i].fs>=60) sum=sum+20;
	}
	sort(a+1,a+n+1,cmp);
	cout<<sum<<"\n";
	for(ll i=1;i<=n;i++)
	{
		if(a[i].fs!=a[i-1].fs) num=i;
		if(num<=k) cout<<num<<" "<<a[i].name<<" "<<a[i].fs<<"\n";
	}
	return 0;
}
