#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll nex[N],fail[N],top;
string s,t;
char st[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    for(ll i=1;i<=t.size();i++)
    {
        ll j=nex[i];
        while(j&&t[i]!=t[j]) j=nex[j];
        if(t[i]==t[j]) nex[i+1]=j+1;
        else nex[i+1]=0;
    }
    ll j=0,top=0;
    for(ll i=0;i<=s.size();i++)
    {
        top++;
        st[top]=s[i];
        while(j&&s[i]!=t[j]) j=nex[j];
        if(s[i]==t[j]) j++;
        fail[top]=j;
        if(j==t.size())
        {
            top=top-t.size();
            j=fail[top];
        }
    }
    top++;
    st[top]='\0';
    cout<<(st+1);
    return 0;
}
