#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const ll N=1e5+10;
ld kk[N],tt[N],k,t,x,y;
ll i,j,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	kk[0]=1;
	for(ll i=1;i<=n;i++)
	{
		ll opt;
		ld x;
		cin>>opt>>x;
		if(opt==1)
		{
			kk[i]=kk[i-1]*x;
			tt[i]=tt[i-1];
		}
		else
		{
			kk[i]=kk[i-1];
			tt[i]=tt[i-1]+x;
		}		
	}
	while(m--)
	{
		cin>>i>>j>>x>>y;
		k=kk[j]/kk[i-1];
		t=tt[j]-tt[i-1];
		cout<<fixed<<setprecision(3)<<kk[j]<<"   "<<kk[i-1]<<"       "<<k<<" "<<t<<"         ";
		cout<<fixed<<setprecision(3)<<k*(x*cos(t)-y*sin(t))<<" "<<k*(x*sin(t)+y*cos(t))<<"\n";
	}
	return 0;
}
