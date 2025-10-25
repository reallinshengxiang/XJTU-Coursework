#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,x,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>x>>k;
		if(x%k) cout<<"1\n"<<x<<"\n";
		else
		{
			cout<<"2\n"<<x-1<<" "<<1<<"\n";
		}
	}
	return 0;
}
