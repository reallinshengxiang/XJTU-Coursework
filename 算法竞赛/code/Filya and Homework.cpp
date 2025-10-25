#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=1e5+10;
ll a[N],n,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	num=unique(a+1,a+n+1)-(a+1);
	if(num<=2) cout<<"YES";
	else if(num==3&&a[2]*2==a[1]+a[3]) cout<<"YES";
	else cout<<"NO";
	return 0;
}