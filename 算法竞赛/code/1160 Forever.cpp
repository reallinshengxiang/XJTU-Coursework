#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
struct zh{
	ll nn,a;
};
zh b[N];
ll k,m,n,sum,cnt,a[N];
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
void check()
{
	ll num=0,nn=0,t,sum=0;
	if(a[k]==0) return;
	for(ll i=k;i>=1;i--) num=num*10+a[i],sum=sum+a[i];
	if(sum!=m) return;
//	cout<<sum<<"\n";
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
		b[cnt].a=t;
	}
}
void dfs(ll step)
{
	if(step==k+1) 
	{
		//for(ll i=k;i>=1;i--) cout<<a[i];
		//cout<<"\n";
		check();
		return;
	}
	for(ll i=0;i<=9;i++)
	{
		if(sum+i>m||sum+i+(k-step)*9<m) continue;
		sum=sum+i;
		a[step]=i;
		dfs(step+1);
		sum=sum-i;
	}
}
bool cmp(const zh x,const zh y)
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
	for(ll ii=1;ii<=n;ii++)
	{
		cin>>k>>m;
		cnt=0;
		dfs(1);
		cout<<"Case "<<ii<<"\n";
		if(cnt==0) cout<<"No Solution\n";
		else
		{
			sort(b+1,b+cnt+1,cmp);
			for(ll j=1;j<=cnt;j++) cout<<b[j].nn<<" "<<b[j].a<<"\n";
		}
	}
	return 0;
} 
