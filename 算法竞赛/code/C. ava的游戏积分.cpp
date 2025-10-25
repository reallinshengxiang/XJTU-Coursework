#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010],n,m,cnt,num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m>(n+1)*n/2) cout<<"It is raining!";
	for(ll i=n;i>=1;i--)
	{
		if(m>=i)
		{
			cnt++;
			a[cnt]=i;
			m=m-i;
		}
		if(m==0)
		{
			cout<<cnt<<"\n";
			for(ll j=cnt;j>=1;j--) cout<<a[j]<<" ";
			return 0;
		}
	}
	return 0;
 } 
