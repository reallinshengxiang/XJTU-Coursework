#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct xs{
    ll qx,xf;
};
xs a[1000010];
ll vis[700070],n,flag,last,ans;
priority_queue<long long>q;
bool cmp(xs aa,xs bb)
{
    if(aa.qx>bb.qx) return 1;
    if(aa.qx==bb.qx&&aa.xf>bb.xf) return 1;
    return 0;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i].qx>>a[i].xf;
    sort(a+1,a+n+1,cmp);
    ll j=1;
    for(ll i=a[1].qx;i>=1;i--)
    {
        while(j<=n)
        {
            if(a[j].qx<i) break;
            q.push(a[j].xf);
            j++;
        }
        if(q.empty()) continue;
        ans=ans+q.top();
        q.pop();
    }
    cout<<ans;
    return 0;
}
