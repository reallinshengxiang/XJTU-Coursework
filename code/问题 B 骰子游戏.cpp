#include<bits/stdc++.h>
using namespace std;
#define ll long long
double ans,p[2][10],sum[2][10],dp[2010][2010],p1,p2,pp,pa,pb;
ll aa,bb;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>aa>>bb;
    for(ll i=1;i<=6;i++)
    {
        cin>>p[0][i];
        sum[0][i]=sum[0][i-1]+p[0][i];
    }
    for(ll i=1;i<=6;i++)
    {
        cin>>p[1][i];
        sum[1][i]=sum[1][i-1]+p[1][i];
    }
    for(ll i=1;i<=5;i++)
    {
        p1=p1+sum[1][i]*p[0][i+1];
        p2=p2+sum[0][i]*p[1][i+1];
    }
    pp=1-p1-p2;
    pa=p1/(1-pp);
    pb=p2/(1-pp);
    dp[0][0]=1;
    for(ll j=1;j<=aa;j++) dp[0][j]=dp[0][j-1]*pb;
    for(ll i=1;i<=bb;i++) dp[i][0]=dp[i-1][0]*pa;
    for(ll i=1;i<=bb-1;i++)
    {
        for(ll j=1;j<=aa-1;j++)  dp[i][j]=dp[i-1][j]*pa+dp[i][j-1]*pb;
        dp[i][aa]=dp[i][aa-1]*pb;
    }
    for(ll j=1;j<=aa-1;j++) dp[bb][j]=dp[bb-1][j]*pa;
    for(ll i=0;i<=aa-1;i++) ans=ans+dp[bb][i];
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}
