#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll st,ed,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>st>>ed;
	for(ll i=st;i<=ed;i++)
	{
		cout<<setiosflags(ios::left)<<setw(5)<<i;
		num++;
		if(num%5==0||i==ed) cout<<"\n";
	}
	cout<<"Sum = "<<(st+ed)*num/2;
	return 0;
}
