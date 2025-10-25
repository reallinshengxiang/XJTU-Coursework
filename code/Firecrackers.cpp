#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll T,n,m,a,b,num,cnt,s[N],t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>a>>b;
		for(ll i=1;i<=m;i++) cin>>s[i];
		sort(s+1,s+m+1);
	    num=abs(b-a)-1;
		cnt=0;
		t=min(m,num);
		if(a<b)
		{
			for(ll i=1;i<=min(m,num);i++)
		    {
		  	   while(i+s[t]>b-1&&t>=1) t--;
			   if(t==0) break;
			   if(i+s[t]<=b-1) cnt++,t--;
		    }
		}
		else
		{
			for(ll i=1;i<=min(m,num);i++)
		    {
		  	   while(i+s[t]>n-b&&t>=1) t--;
			   if(t==0) break;
			   if(i+s[t]<=n-b) cnt++,t--;
		    }
		}
		cout<<cnt<<"\n";
	}
	return 0;
}