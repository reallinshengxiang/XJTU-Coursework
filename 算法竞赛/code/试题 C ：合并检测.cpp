#include<bits/stdc++.h>
using namespace std;
#define ll long long
double pp,qq,ans,num=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll k=1;k<=100;k++)
	{
		pp=1;
		for(ll i=1;i<=k;i++) pp=pp*0.99;
		ans=(num/k)*pp+(num/k)*(1-pp)*(k+1);
		cout<<k<<"  "<<ans<<"\n";
	}
	return 0;
}
