#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110],x,flag,n,l,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	cin>>x;
	if(a[2]>a[1]) flag=1;
	else flag=0;
	l=1;
    r=n;
    if(flag)
    {
    	while(l<=r)
        {
    	    ll mid=(l+r)/2;
    	    if(a[mid]>=x) r=mid-1;
    	    else l=mid+1;
	    }
	    if(a[l]!=x) cout<<"-1";
	    else cout<<l;
	    return 0;
	}
	else
	{
		while(l<=r)
        {
    	    ll mid=(l+r)/2;
    	    if(a[mid]<=x) r=mid-1;
    	    else l=mid+1;
	    }
	    if(a[l]!=x) cout<<"-1";
	    else cout<<l;
	    return 0;
	} 
}
