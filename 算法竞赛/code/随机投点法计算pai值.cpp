#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll mod=1e3;
ll sum,n,x,y;
double xx,yy,ss,qq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		x=rand()%mod;
		xx=x*1.0/mod;
		y=rand()%mod;
		yy=1-y*1.0/mod;
		ss=ss+xx;
		qq=qq+yy;
		if(xx*xx+yy*yy<=1) sum++;
		//cout<<fixed<<setprecision(5)<<sum*1.0/i*4<<"  "<<ss*1.0/i<<"\n";
	}
	cout<<fixed<<setprecision(5)<<sum*1.0/n*4<<"  "<<ss*1.0/n<<"  "<<qq*1.0/n;
	return 0;
}
