#include<iostream>
#include<deque>
#include<string.h>
using namespace std;
#define ll long long
ll a[22]={5,88,12,56,71,28,33,43,93,17};
ll h[22],k[22],ans;
deque<ll> dq[22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=0;i<=9;i++)
	{
		ll t=0;
		while(h[(a[i]+t)%13]!=0) t++;
		h[(a[i]+t)%13]=a[i];
		k[(a[i]+t)%13]=1+t;
		ans=ans+1+t;
	}
	cout<<ans/10.0<<"\n";
	memset(h,0,sizeof(h));
	memset(k,0,sizeof(k));
	ans=0;
	for(ll i=0;i<=9;i++)
	{
		if(h[a[i]%13]==0) 
		{
			h[a[i]%13]=a[i];
			k[a[i]%13]=1;
			ans++;
		}
		else
		{
			ll t=1,flag=1,q=1;
			while(h[(a[i]+t*t*flag)%13]!=0) 
			{
				flag=-flag;
				q++;
				if(q%2==1) t++;
			}
			h[(a[i]+t*t*flag)%13]=a[i];
			k[(a[i]+t*t*flag)%13]=1+q;
			ans=ans+1+q;
		}
	}
	cout<<ans/10.0<<"\n";
	ans=0;
    memset(h,0,sizeof(h));
	memset(k,0,sizeof(k));
	for(ll i=0;i<=9;i++)
	{
		h[a[i]%13]++;
		dq[a[i]%13].push_front(a[i]);
		ans=ans+h[a[i]%13];
	}
	cout<<ans/10.0;
    return 0;
}
