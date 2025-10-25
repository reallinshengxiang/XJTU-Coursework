#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e6+10;
stack<ll> st;
ll n,a[N],ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if(st.empty()) ans[i]=0;
        else ans[i]=st.top();
        st.push(i);
    }
    for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
