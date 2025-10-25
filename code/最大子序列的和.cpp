#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[1010],ansi,ansj,n,flag,sum,maxx,j;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	flag=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0) flag=0;
	}
	if(flag)
	{
		cout<<"0 "<<a[1]<<" "<<a[n];
		return 0;
	}
	sum=0;
	maxx=0;
	j=1;
	for(ll i=1;i<=n;i++)
	{
		sum=sum+a[i];
		if(sum<0)
		{
			j=i+1;
			sum=0;
	    }
	    if(sum>maxx)
	    {
	    	maxx=sum;
	    	ansj=j;
	    	ansi=i;
		}
	}
	cout<<maxx<<" "<<ansj-1<<" "<<ansi-1;
	return 0;
}
