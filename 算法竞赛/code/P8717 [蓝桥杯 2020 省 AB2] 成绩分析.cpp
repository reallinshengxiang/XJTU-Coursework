#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
ll n,a[N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],ans=ans+a[i];
	sort(a+1,a+n+1);
	cout<<a[n]<<"\n"<<a[1]<<"\n"<<fixed<<setprecision(2)<<(double)(ans*1.0)/n;
	return 0;
}
