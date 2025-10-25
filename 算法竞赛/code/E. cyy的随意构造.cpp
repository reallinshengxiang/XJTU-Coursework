#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000010],b[1000010],t,q,p;
void print(ll st,ll ed)
{
	for(ll i=st;i<=ed;i++) cout<<a[i]<<" "; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		if(n%2==1)  cout<<"-1";
		else 
		{
			cout<<n/2<<"\n";
			print(1,n/2);
		}
		return 0;
	}
	for(ll i=1;i<=n;i++) 
	{
		b[i]=b[i-1]+a[i];
		if(b[i]==n)
		{
			cout<<i<<"\n";
			print(1,i);
			return 0;
		}
	}	
	ll t=1;
	while(a[t]<=2&&t<n) t++;
	t=t-1;
	if(b[t]>n)
	{
		p=0;
		for(ll i=1;i<=t;i++)
		{
			if(b[i]>n)
			{
				p=i;
				break;
			}
		}
		cout<<p-1<<"\n";
		print(2,p);
	}
	else
	{
		p=0;
		for(ll i=t+1;i<=n;i++)
		{
			if(b[i]>n)
			{
				p=i;
				break;
			}
		}
		if(b[p]-n>a[t]) cout<<"-1";
		else
		{
			q=0;
			for(ll i=1;i<=t;i++)
		    {
			     if(b[p]-n<=b[i]) 
			     {
			     	q=i;
			     	break;
				 }
		    }
		    if(b[p]-n==b[q]) 
			{
				cout<<p-q<<"\n";
				print(q+1,p);
			}
		    else 
			{
				cout<<p-q+1<<"\n";
				cout<<"1 ";
				print(q+1,p);
			}
		}		
	}
	return 0;
}
