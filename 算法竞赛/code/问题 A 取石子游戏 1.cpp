#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	if((n%(k+1))==0) cout<<2;
	else cout<<1;
	return 0;
 } 
