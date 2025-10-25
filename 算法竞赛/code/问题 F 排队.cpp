#include<bits/stdc++.h>
using namespace std;
#define ll long long
double sum,t[1010];
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>t[i];
		sum=sum+t[i];
	}
	for(ll i=1;i<=n;i++) cout<<fixed<<setprecision(2)<<(sum-t[i])/2<<" ";
	return 0;
}
