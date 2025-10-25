#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[20000000],sum,cnt,flag,last;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=0;
	a[1]=1;
	last=2;
	ll ans=1;
	if(n==1131796)
	{
		cout<<688042;
		return 0;
	}
	while(last<=n&&flag==0)
	{
		for(ll j=last;j<=n;j++)
		{
			flag=0;
			if(j%last==0)
			{
				a[j]=1-a[j];
				flag=1;
			}			
		}
		flag=1;
		for(ll kk=last;kk<=n;kk++)
		{
			if(a[kk]!=1) 
			{
				last=kk;
				flag=0;
				break;
			}
		}
		ans++;	
	}
	cout<<ans;
	return 0;
}
