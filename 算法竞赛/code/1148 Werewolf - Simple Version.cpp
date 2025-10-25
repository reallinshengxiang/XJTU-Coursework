#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=110;
ll a[N],n,p[N];
string s[N];
ll to_ll(string s)
{
	ll ans=0;
	for(ll i=1;i<s.size();i++) ans=ans*10+s[i]-'0';
	return ans; 
}
ll to_flag(string s)
{
	if(s[0]=='-') return 1;
	return 0;
}
ll check(ll x,ll y)
{
	ll num=0;
	for(ll i=1;i<=n;i++) a[i]=0;
	a[x]=a[y]=1;
	for(ll i=1;i<=n;i++)
	{
		if(a[to_ll(s[i])]!=to_flag(s[i])) num++,p[num]=i;
    }
    if(num!=2) return 0;
    if(p[1]==x&&p[2]==y) return 0;
    if(p[1]==y&&p[2]==x) return 0;
    for(ll i=1;i<=2;i++)
    {
    	if(p[i]==x||p[i]==y) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
		//	cout<<i<<"  "<<j<<"  "<<check(i,j)<<"\n";
			if(check(i,j)==1) 
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
	return 0;
}
