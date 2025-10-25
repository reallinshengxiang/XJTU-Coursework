#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll ans,last,x,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	last=0;
	while(cin>>x)
	{
		if(x==0) break;
		if(x>last) t=6;
		else t=4;
		ans=ans+abs(x-last)*t+5;
		last=x;
	}
	cout<<ans;
	return 0;
}
