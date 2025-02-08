#include<bits/stdc++.h>
using namespace std;
long long f1,f2,a,b,c,n,ans;
long long f(long long);
int main()
{
    cin>>f1>>f2>>a>>b>>c>>n;
    ans=f(n);
    while(ans<0) ans=ans+1000007;
    cout<<ans<<endl;
}
long long f(long long x)
{
   
    if(x==1) return f1%1000007;
    else if(x==2) return f2%1000007;
    return (f(x-1)*b+f(x-2)*a+c)%1000007;
}
