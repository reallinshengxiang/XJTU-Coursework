#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=5e5+10;
ll n;
ld a[N],b,s,ave,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ave=s/n;
	for(ll i=1;i<=n;i++)
	{
		b=min(a[i],s/(n-i+1));
		s=s-b;
		ans=ans+(b-ave)*(b-ave)/n;
	}
	cout<<fixed<<setprecision(4)<<sqrt(ans); 
	return 0;
} 
