#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10010],maxx,flag,n;
void print()
{
	for(ll i=1;i<=maxx;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
void dfs(ll step,ll last)
{
	if(step>=maxx+1) 
	{
		if(a[maxx]==n) flag=1;
		return;
	}
	for(ll i=step-1;i>=last;i--)
	{
		for(ll j=i;j>=1;j--)
        {
		   ll ff=a[step]=a[i]+a[j];
           for(ll k=last+1;k<=maxx;k++) ff<<=1;
           if(ff<n)  break;
           dfs(step+1,i+1);
           if(flag)  return;
           a[step]=0;
        }
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1)
	{
		cin>>n;
		if(n==0) break;
		if(n==1) 
		{
		    cout<<"1\n";
			continue;	
		}
		flag=0;
		a[1]=1;
		for(ll i=2;i<=n;i++)
		{
			maxx=i;
			dfs(2,1);
			if(flag)
			{
				print();
				break;
			}
		}
	}
	return 0;
}
