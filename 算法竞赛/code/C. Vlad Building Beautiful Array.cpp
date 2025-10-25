#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll T,n,f1,f2,num,a[N],b[N],sum1[N],sum2[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(ll i=1;i<=n;i++) b[i]=a[i]%2;
		sum1[0]=sum2[0]=0;
		f1=f2=0;
		for(ll i=1;i<=n;i++) 
		{
			sum1[i]=sum1[i-1];
			sum2[i]=sum2[i-1];
			if(b[i]==1) sum1[i]++;
			if(b[i]==0) sum2[i]++;
		}
		for(ll i=1;i<=n;i++)
		{
			if(i==1)
			{
				if(a[i]%2) f1=1;
				else f2=1;
				continue;
			}
			if(a[i]==a[i-1]) continue;
			if(a[i]%2&&sum1[i-1]==0)  f1=1;
		    else if(a[i]%2==0&&sum1[i-1]==0) f2=1;
		}	
		if(f1&&f2) cout<<"NO\n";
		else cout<<"YES\n";		
	}
	return 0;
} 
