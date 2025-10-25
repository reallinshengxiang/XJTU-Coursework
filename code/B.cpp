#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll i,c,p,ans,y,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>i>>c>>p;
	if(2*i>=c) i=c/2;
	y=(c-2*i)/3;
	x=i;
	cout<<min(x+y,p);
	return 0;
}
