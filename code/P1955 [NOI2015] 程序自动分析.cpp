#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll xx,yy;
};
node pp;
ll flag,T,n,f[200010],cnt;
ll find_set(ll x)
{
    if(f[x]!=x) f[x]=find_set(f[x]);
    return  f[x];
}
void merge(ll x,ll y)
{
    if(find_set(x)!=find_set(y)) f[find_set(x)]=find_set(y);
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        unordered_map<ll,ll> mp;
        queue<node> que;
        cin>>n;
        for(ll i=1;i<=2*n;i++) f[i]=i;
        cnt=0;
        for(ll i=1;i<=n;i++)
        {
            ll x,y,e;
            cin>>x>>y>>e;
            if(mp[x]==0)
            {
                cnt++;
                mp[x]=cnt;
            }
            if(mp[y]==0)
            {
                cnt++;
                mp[y]=cnt;
            }
            if(e==1) merge(mp[x],mp[y]);
            else  que.push({mp[x],mp[y]});
        }
        flag=1;
        while(!que.empty()&&flag)
        {
            pp=que.front();
            que.pop();
            if(find_set(pp.xx)==find_set(pp.yy)) flag=0;
        }
        if(flag)  cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
