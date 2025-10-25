#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,k,a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll num1,num2;
	cin>>n>>k;
	for(ll i=1;i<=k;i++) cin>>a[i]>>b[i];
	sort(a+1,a+k+1);
	sort(b+1,b+k+1);
	num1=unique(a+1,a+k+1)-(a+1);
	num2=unique(b+1,b+k+1)-(b+1);
	cout<<n*n-(n-num1)*(n-num2);
	return 0;
}
