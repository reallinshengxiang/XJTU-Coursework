#include<bits/stdc++.h>
using namespace std;
#define ll long long
double a[100010],b[100010],n;
ll l;
ll check(double x)
{
    b[0]=0;
    for(ll i=1;i<=n;i++) b[i]=b[i-1]+a[i]-x ;
    double minn=b[0];
    for(ll i=l;i<=n;i++)
    {
        minn=min(minn,b[i-l]);
        if(b[i]-minn>=0) return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    for(ll i=1;i<=n;i++)   cin>>a[i];
    double l=0,r=2020,mid;
    while(r-l>=0.000001)
    {
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    ll ans=r*1000;
    cout<<ans;
    return 0;
}
