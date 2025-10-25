#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll num[11]={0,1,2,3,4,5,6,7,8,9},n,a,b,c;
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	do{
		for(ll i=1;i<=7;i++)
		{
			a=0;
		    for(ll ii=1;ii<=i;ii++) a=a*10+num[ii];
			for(ll j=i+1;j<=8;j++)
			{
				b=0,c=0;
			    for(ll ii=i+1;ii<=j;ii++) b=b*10+num[ii];
			    for(ll ii=j+1;ii<=9;ii++) c=c*10+num[ii];
				if(b%c!=0) continue;
				mp[a+b/c]++;
			}
		}
	}while(next_permutation(num+1,num+10));	
	cout<<mp[n];
	return 0;
}
