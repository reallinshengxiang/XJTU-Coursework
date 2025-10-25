#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=1;
	while(n>1)
	{
		n=n/2;
		cnt++;
	} 
	cout<<cnt<<"\n";
	return 0;
}
