#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[5],n;
double b[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1) 
	{
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		cout<<a[3];
	}
	else
	{
		cin>>b[1]>>b[2]>>b[3];
		sort(b+1,b+4);
		cout<<b[3];
	}
	return 0;
}
