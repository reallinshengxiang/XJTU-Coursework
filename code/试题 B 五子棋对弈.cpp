#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#pragma GCC optimize(2)
ll a[10][10],ans,sum;
ll check()
{
	ll sum=0,tt=0;
	for(ll ii=1;ii<=5;ii++)
	{
		tt=0;
		for(ll jj=1;jj<=5;jj++) sum=sum+a[ii][jj],tt=tt+a[ii][jj];
		if(tt==0||tt==5) return 0;
	}
	for(ll jj=1;jj<=5;jj++)
	{
		tt=0;
		for(ll ii=1;ii<=5;ii++) tt=tt+a[ii][jj];
		if(tt==0||tt==5) return 0;
	}
	if(sum!=13) return 0;
	sum=0;
	for(ll ii=1;ii<=5;ii++) sum=sum+a[ii][ii];
	if(sum==0||sum==5) return 0;
	sum=0;
	for(ll ii=1;ii<=5;ii++) sum=sum+a[ii][6-ii];
	if(sum==0||sum==5) return 0;
	return 1;
}
void print()
{
	for(ll ii=1;ii<=5;ii++)
	{
		for(ll jj=1;jj<=5;jj++) cout<<a[ii][jj]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	for(ll i=1;i<=(1<<25)-1;i++)
	{
		ll x=i;
		for(ll ii=1;ii<=5;ii++)
		{
			ll y=x%32;
			for(ll jj=1;jj<=5;jj++)
			{
				a[ii][jj]=((y>>(jj-1))&1);
			}
			x=x/32;
		}
	//	cout<<x<<"\n";
		if(x!=0) 
		{
			//cout<<i<<"  "<<x<<"\n";
			print();
			return 0;
		}
		if(check()) 
		{
			ans++;
			if(ans<=100) print();
		}
		sum++;
	}
	cout<<sum<<" "<<ans;
	return 0;
}
/*3126376*/
