#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,flag,a[66],b[66],minn,sum,tt,f;
bool cmp(ll x,ll y)
{
    return x>y;
}
void dfs(ll step,ll nn,ll mm,ll len)
{
    if(step>=n+1)
    {
        if(nn==mm) flag=1;
        else flag=2;
        return;
    }
    if(flag)  return;
    if(nn>mm) return;
    f=0;
    for(ll i=1;i<=nn;i++)
    {
        if(b[i]==len) f++;
    }
    if(f+(n-step+1)<mm) return;
    ll x=a[step];
    for(ll i=1;i<=nn;i++)
    {
        if(x+b[i]<=len)
        {
            b[i]=b[i]+x;
            dfs(step+1,nn,mm,len);
            b[i]=b[i]-x;
        }
    }
    b[nn+1]=x;
    dfs(step+1,nn+1,mm,len);
    b[nn+1]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n)
    {
        if(n==0) break;
        sum=0;
        minn=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
            minn=max(minn,a[i]);
        } 
        sort(a+1,a+n+1,cmp);
        tt=1;
        memset(b,0,sizeof(b));
        for(ll i=sum/minn;i>=1&&tt;i--)
        {
            if(sum%i==0) 
            {
                flag=0;
                dfs(1,1,i,sum/i);
                if(flag)
                {
                    cout<<sum/i<<"\n";
                    tt=0;
                }
            }
        }
    }
    return 0;
}
