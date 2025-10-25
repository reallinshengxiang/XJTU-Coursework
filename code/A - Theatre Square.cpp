#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>a;
	x=n/a;
	if(x*a<n) x++;
	y=m/a;
	if(y*a<m) y++;
	cout<<x*y;
	return 0;
} 
