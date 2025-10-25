#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
string s1,s2;
ll ans,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2;
	for(ll i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i]) a[i]=1;
	}
	for(ll i=0;i<s1.size();i++)
	{
		if(a[i]) a[i]=0,a[i+1]=1-a[i+1],ans++;
	}
	cout<<ans;
	return 0;
}
