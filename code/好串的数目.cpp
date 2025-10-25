#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
string s;
ll n,a[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>s;
    n=s.size();
    for(ll i=0;i<s.size();i++) a[i+1]=s[i]-'0';
    for(ll len=3;len<=n;len++)
    {
    	for(ll st=1;st+len-1<=n;st++)
    	{
    		ll ed=st+len-1;
    		ll num=0;
    		for(ll k=st+1;k<=ed;k++)
    		{
    			if(!(a[k]==a[k-1]||a[k]==a[k-1]+1)) num++;
			}
			if(num<=1) ans++;
		}
	}
	cout<<ans+n+n-1;
	return 0;
}
