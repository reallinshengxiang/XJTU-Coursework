#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll num,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s)
	{
		ll len=s.size();
		sum=sum+len;
		num++;
	}
	cout<<fixed<<setprecision(2)<<sum*1.0/num;
	return 0;
 } 
