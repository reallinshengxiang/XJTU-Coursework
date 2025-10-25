#include <bits/stdc++.h>
using namespace std;
#define ll long long 
using maxType=__int128;
void print(maxType x){
    stack<int>o;
    while(x)o.push(x%10),x/=10;
    while(!o.empty())cout<<o.top(),o.pop();
}
ll n,a,b;
maxType c(ll n,ll m)
{
	maxType ans=1;
	for(ll i=1;i<=m;i++)
	{
		ans=ans*(n-i+1);
		ans=ans/i;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>a>>b;
	print(c(a+n,n)*c(b+n,n));
	return 0;
}
