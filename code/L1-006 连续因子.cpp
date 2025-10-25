#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,st,ed,x,t,len,maxx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	st=ed=0;
	for(ll i=2;i<=sqrt(n);i++)
	{
		x=i;
		t=n;
		len=0;
		if(t%x) continue;
		while(t%x==0)
		{
			t=t/x;
			x++;
			len++;
		} 
	//	cout<<i<<" "<<len<<"\n";
		if(len>maxx)
		{
			maxx=len;
			st=i;
			ed=x-1;
	    }
	}
	if(maxx==0)
	{
		cout<<"1\n"<<n;
		return 0;
	}
	cout<<maxx<<"\n";
	for(ll i=st;i<ed;i++) cout<<i<<"*";
	cout<<ed;
	return 0;
} 
