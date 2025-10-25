#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4;
ll T,x,n,cnt,a[N],xx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>x>>n;
		cnt=0;
		for(ll i=1;i<=sqrt(x);i++)
		{
			if(x%i==0)
			{
				if(i!=sqrt(x))
				{
					a[++cnt]=i;
				    a[++cnt]=x/i;
				}
				else a[++cnt]=i;
			}
		}
		sort(a+1,a+cnt+1);
		ll l=1,r=cnt,mid;
		xx=x/n;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[mid]>=xx) r=mid-1;
			else l=mid+1;
		}
		while(a[l]>xx) l--;
		cout<<a[l]<<"\n";
	}
	return 0;
}
