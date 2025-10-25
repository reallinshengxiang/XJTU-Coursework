#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,n,t1,t2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>n;
	t1=n/(5*a+2*b);
	if(t1*(5*a+2*b)==n)
	{
		cout<<t1*7;
		return 0;
	}
	n=n-t1*(5*a+2*b);
	if(n<=5*a)
	{
		t2=n/a;
		if(n%a!=0) t2++;
		cout<<t1*7+t2;
	}
	else if(n<=5*a+b) cout<<t1*7+6;
	else cout<<t1*7+7;
	return 0;
}
