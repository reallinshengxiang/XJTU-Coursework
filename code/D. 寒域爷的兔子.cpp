#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll N=2;
struct matrix{
    ll a[N+1][N+1];
};
ll n,m;
matrix operator * (const matrix &a,const matrix &b)
{
    matrix c;
    memset(c.a,0,sizeof(c.a));
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=N;j++)
        {
            for(ll k=1;k<=N;k++) c.a[i][j]=(c.a[i][j]+(a.a[i][k]*b.a[k][j])%m)%m;
        }
    }
    return c;
}
matrix pow_matrix(matrix a,ll n)
{
    matrix ans;
    memset(ans.a,0,sizeof(ans.a));
    for(ll i=1;i<=N;i++) ans.a[i][i]=1;
    while(n)
    {
        if(n&1) ans=ans*a;
        a=a*a;
        n>>=1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    matrix ma;
    ma.a[1][1]=1;
    ma.a[1][2]=1;
    ma.a[2][1]=1;
    ma.a[2][2]=0;
    ma=pow_matrix(ma,n);
    cout<<(ma.a[2][1]*2)%m;
    return 0;
}
