#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10010;
ll a[N],n,cnt,sum,p,ans[N],len=1;
void mul(ll x)
{
	for(ll i=1;i<=len;i++) ans[i]=ans[i]*x;
	for(ll i=1;i<=len;i++)
	{
		ans[i+1]=ans[i+1]+ans[i]/10;
		ans[i]=ans[i]%10;
	}
	while(ans[len+1]>0)
	{
		len++;
		ans[len+1]=ans[len]/10;
		ans[len]=ans[len]%10;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=2;i<=n;i++) 
	{
		sum=sum+i;
		if(sum>=n)
		{
			p=i;
			break;
		}
    }
	if(sum==n)
	{
		for(ll i=2;i<=p;i++) 
		{
			cnt++;
			a[cnt]=i;
		}
	}
	else if(sum==n+1)
	{
		for(ll i=3;i<=p+1;i++) 
		{
			cnt++;
			a[cnt]=i;
		}
	}
	else
	{
		for(ll i=2;i<=p;i++)
		{
			if(i==sum-n) continue;
			cnt++;
			a[cnt]=i;
		}
	}
	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
	cout<<"\n";
	ans[1]=1;
	for(ll i=1;i<=cnt;i++) mul(a[i]);
	for(ll i=len;i>=1;i--) cout<<ans[i];
	return 0;
}
