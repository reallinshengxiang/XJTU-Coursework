#include<bits/stdc++.h>
using namespace std;
#define ll int
ll nex[1000010],n,m;
string p,s,ss,qq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	cin>>p;
	n=p.size();
	m=s.size()*2;
    nex[0]=0;
    nex[1]=0;
    ss=s+s;
    for(ll i=1;i<=n-1;i++)
    {
    	ll j=nex[i];
    	while(j&&p[i]!=p[j]) j=nex[j];
    	if(p[i]==p[j]) nex[i+1]=j+1;
    	else nex[i+1]=0;
	}
	ll j=0;
	for(ll i=0;i<=m-1;i++)
	{
		while(j&&ss[i]!=p[j]) j=nex[j];
		if(ss[i]==p[j]) j++;
		if(j==n) 
		{
			cout<<"Yes";
			return 0;
		}		
	}
	reverse(ss.begin(),ss.end());
	j=0;
	for(ll i=0;i<=m-1;i++)
	{
		while(j&&ss[i]!=p[j]) j=nex[j];
		if(ss[i]==p[j]) j++;
		if(j==n) 
		{
			cout<<"Yes";
			return 0;
		}		
	}
	cout<<"No";
	return 0;
 } 
