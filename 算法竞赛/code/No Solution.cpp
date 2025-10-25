#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,m,n,sum,cnt;
const ll N=1e5+10;
struct zh{
	ll nn,a;
};
zh b[N];
bool is_prime(ll x)
{
	if(x==1) return 0;
	if(x==2) return 0;
	for(ll i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
void dfs(ll step)
{
	if(step==k+1) check();
	for(ll i=0;i<=9;i++)
	{
		if(sum+i>m) continue;
		sum=sum+i;
		a[step]=i;
		dfs(step+1);
		sum=sum-i;
	}
}
void check()
{
	ll num=0,nn=0,t;
	if(num[k]==0) return;
	for(ll i=k;i>=1;i--) num=num*10+a[i];
	t=num;
	num=num+1;
	while(num!=0)
	{
		nn=nn+num%10;
		num=num/10;
	}
	ll xx=__gcd(nn,m);
	if(is_prime(xx)) 
	{
		cnt++;
		b[cnt].nn=nn;
		b[cnt].a=num;
	}
}
bool cmp(zh x,zh y)
{
	if(x.nn<y.nn) return 1;
	if(x.nn==y.nn&&x.a<y.a) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>k>>m;
		cnt=0;
		dfs(1);
		cout<<"Case "<<i<<"\n";
		if(cnt==0) cout<<"No Solution\n";
		else
		{
			sort(a+1,a+cnt+1,cmp);
			for(ll j=1;j<=cnt;j++) cout<<b[j].nn<<" "<<b[j].a<<"\n";
		}
	}
	return 0;
} 
