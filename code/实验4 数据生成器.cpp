#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x,num,a[1010][22],maxnum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("1.in","w",stdout);
	srand(time(0));
	for(ll i=0;i<=19;i++)
	{
		num=0;
		maxnum=rand()%3;
		for(ll j=0;j<=999;j++)
		{
			x=rand()%2;
			if(x==1) num++;
			if(num>=maxnum) x=0;
			a[j][i]=x;
		}
	}
	for(ll i=0;i<=999;i++)
	{
		for(ll j=0;j<=19;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}



