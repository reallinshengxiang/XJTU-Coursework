#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum,masks[20]={0,9090400,8499400,5926800,8547000,4958200,4422600,5751200,4175600,6309600,5865200,6604400,4635000,10663400,8087200,4554000};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=15;i++) sum=sum+masks[i];
	cout<<sum;
	return 0;
}
