#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll prime[10]={0,2,3,5,7,11,13,17,19,23};
ll maxnum,minsum,n;
void dfs(ll step,ll last,ll sum,ll num)
{
	if((maxnum<num)||(maxnum==num&&sum<minsum))
	{
		maxnum=num;
		minsum=sum;
	}
	if(step==10) return;
	for(ll i=1;i<=last;i++)
	{
		if(sum*prime[step]>n) break;
		sum=sum*prime[step];
		dfs(step+1,i,sum,num*(i+1));
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dfs(1,30,1,1);
	cout<<minsum;
	return 0;
} 
