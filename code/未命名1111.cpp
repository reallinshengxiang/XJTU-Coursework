#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll a[12]={0,1,2,3,4,5,6,7,8,9,11},x;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x;
	ll l=1,r=10;
	sort(a+1,a+11,cmp);
	for(ll i=1;i<=10;i++) cout<<a[i]<<"  "; 
	return 0;
}
