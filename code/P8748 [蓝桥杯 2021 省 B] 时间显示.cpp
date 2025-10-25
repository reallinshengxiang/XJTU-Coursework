#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t1,t2,t3;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	n=n/1000;
	t1=n/3600;
	if(t1%24<=9) cout<<"0";
	cout<<t1%24<<":";
	n=n-t1*3600;
	t2=n/60;
	if(t2%60<=9) cout<<"0";
	cout<<t2%60<<":";
	n=n-t2*60;
	t3=n;
	if(t3<=9) cout<<"0";
	cout<<t3;
	return 0;
}
