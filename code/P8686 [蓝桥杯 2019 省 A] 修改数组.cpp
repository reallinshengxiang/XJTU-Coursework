#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll s[N],a,n;
ll find_set(ll x)
{
	if(x!=s[x]) s[x]=find_set(s[x]);
	return s[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=N-1;i++) s[i]=i;
	for(ll i=1;i<=n;i++)
	{
		cin>>a;
		a=find_set(a);
		s[a]=a+1;
		cout<<a<<" ";
	}
	return 0;
} 
