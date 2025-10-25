#include<bits/stdc++.h>
using ll=long long;
using namespace std;
ll m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string s;
ll ans=2,a[5],b[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	a[1]=s[0]-'0';
	a[2]=s[1]-'0';
	a[3]=s[3]-'0';
	a[4]=s[4]-'0';
	for(ll i=1;i<=12;i++)
	{
		for(ll j=0;j<=m[i];j++)
		{
			if(i<=9) b[1]=0,b[2]=i;
			else b[1]=i/10,b[2]=i%10;
			if(j<=9) b[3]=0,b[4]=j;
			else b[3]=j/10,b[4]=j%10;
            ll num=0;
			for(ll k=1;k<=4;k++)
			{
				if(a[k]!=b[k]) num++;
			}
			ans=min(ans,num);
		}
	}
	cout<<ans;
	return 0;
 } 
