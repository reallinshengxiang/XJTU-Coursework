#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10010],x,cnt;
int main()
{
	while(cin>>x)
	{
		if(x==0) break;
		cnt++;
		a[cnt]=x;
	}
	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
}
