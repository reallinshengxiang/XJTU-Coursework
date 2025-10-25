#include<iostream>
using namespace std;
#define ll long long
ll nex[10010],n,m,flag;
string p,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>p;
	n=p.size();
	m=s.size();
    nex[0]=0;
    nex[1]=0;
    for(ll i=1;i<=n-1;i++)
    {
    	ll j=nex[i];
    	while(j&&p[i]!=p[j]) j=nex[j];
    	if(p[i]==p[j]) nex[i+1]=j+1;
    	else nex[i+1]=0;
	}
	ll j=0;
	flag=1;
	for(ll i=0;i<=m-1;i++)
	{
		while(j&&s[i]!=p[j]) j=nex[j];
		if(s[i]==p[j]) j++;
		if(j==n) 
		{
			cout<<i+1-n<<" ";	
			flag=0;
		}	
	}
	if(flag) cout<<"-1";
	return 0;
 } 
