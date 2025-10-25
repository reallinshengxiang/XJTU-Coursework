#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,p1,p2,a0,a1,b0,b1,ans,x,y;
ll lcm(ll x,ll y)
{
	return x*y/__gcd(x,y);
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>a0>>a1>>b0>>b1;
        ans=0;
        for(ll i=1;i*i<=b1;i++)
        {
            x=i;
            if(b1%x==0)
            {
                if(__gcd(x,a0)==a1&&lcm(x,b0)==b1)  ans++;
                if(b1/x!=x)
                {
                	 if(__gcd(b1/x,a0)==a1&&lcm(b1/x,b0)==b1)  ans++;
				}
                
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
} 
