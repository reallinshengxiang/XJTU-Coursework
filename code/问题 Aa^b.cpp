#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fast_pow(ll x,ll n,ll m)
{
     ll ans=1%m;
     while(n)
     {
        if(n&1) ans=(ans*x)%m;
        x=(x*x)%m;
        n>>=1;
     }
     return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,m;
    cin>>a>>b>>m;
    cout<<fast_pow(a,b,m);
    return 0;
} 
