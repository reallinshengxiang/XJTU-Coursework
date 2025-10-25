#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[20],t,n,cnt,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=0;
	t=0;
	sum=1;
	while(sum<n)
	{
		cnt++;
		if(!t) t=1;
		else t=t*2;
		sum=sum+t;
		a[cnt]=t;
	}
	cout<<cnt<<"\n";
	for(ll i=1;i<=cnt;i++) cout<<a[i]<<" ";
	return 0;
}
