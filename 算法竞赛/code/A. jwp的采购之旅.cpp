#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],n,m,cnt,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cnt=1;
	num=0;
	while(m-a[cnt]>=0&&cnt<=n)
	{
		num++;
		m=m-a[cnt];
		cnt++;
	}
	cout<<num;
	return 0;
 } 
