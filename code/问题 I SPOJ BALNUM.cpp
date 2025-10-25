#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
ll dp[N][60000],num[N],T,pow3[11];
ll change(ll x,ll y) 
{
	ll z;
	z=(x/pow3[y])%3;
	if(z==0||z==2) x=x-z*pow3[y]+pow3[y];
	else x=x+pow3[y];
	return x;
}
ll dfs(ll pos,ll state,ll limit)
{
    ll ans=0;
    if(pos==0) 
    {
        ll x=state;
        for(ll i=0;i<=9&&x;i++)
        {
        	ll y=x%3;
        	x=x/3;
        	if(y==0) continue;
        	if((i&1)&&y==1) return 0;
        	if(!(i&1)&&y==2) return 0;
		}
		return 1;
    }
    if(!limit&&dp[pos][state]!=-1) return dp[pos][state];
    ll up;
    if(limit) up=num[pos];
    else up=9;
    for(ll i=0;i<=up;i++)
    {
        if(state==0&&i==0) ans=ans+dfs(pos-1,0,limit&&i==up);
        else   ans=ans+dfs(pos-1,change(state,i),limit&&i==up);
    }
    if(!limit) dp[pos][state]=ans;
    return ans;
}
ll solve(ll x)
{
    ll len=0;
    while(x)
    {
        len++;
        num[len]=x%10;
        x=x/10;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(len,0,1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l,r;
    pow3[0]=1;
    for(ll i=1;i<=10;i++) pow3[i]=pow3[i-1]*3;
    cin>>T;
    while(T--)
    {
    	cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<"\n";
	} 
    return 0;
}
