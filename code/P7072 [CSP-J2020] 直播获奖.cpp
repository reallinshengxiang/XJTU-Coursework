#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=610;
ll x,n,w,sum,num[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>w;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		num[x]++;
		sum=0;
		for(ll j=600;j>=0;j--)
		{
			sum=sum+num[j];
			if(sum>=max((ll)1,i*w/100)) 
			{
				cout<<j<<" ";
				break;
			}
		}
	}
	return 0;
}
