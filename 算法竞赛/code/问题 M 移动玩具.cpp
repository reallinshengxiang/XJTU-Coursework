#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
    ll x,y;
};
point p1[20],p2[20];
ll vis[20],ans=0x3f3f3f3f3f,cnt1,cnt2;
string a[5],b;
void dfs(ll step,ll sum)
{
    if(sum>ans) return;
    if(step>cnt1)
    {
        ans=sum;
        return;
    }
    for(ll i=1;i<=cnt2;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(step+1,sum+abs(p1[step].x-p2[i].x)+abs(p1[step].y-p2[i].y));
            vis[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(ll i=1;i<=4;i++) cin>>a[i];
    for(ll i=1;i<=4;i++)
    {
        cin>>b;
        for(ll j=0;j<=3;j++)
        {
            if(b[j]<a[i][j])
            {
                cnt1++;
                p1[cnt1]=(point){i,j+1};
            }
            else if(b[j]>a[i][j])
            {
                cnt2++;
                p2[cnt2]=(point){i,j+1};
            }
        } 
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
