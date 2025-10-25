#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
ll f[5],ans; 
int main()
{
	clock_t st,ed;
	st=clock();
	f[1]=f[2]=1;
	for(ll i=3;i<=202202011200;i++)
	{
		f[3]=(f[1]+f[2])%10;
		f[1]=f[2]%10;
		f[2]=f[3];
		if(f[3]==7) ans++; 
	}
	cout<<ans;
	ed=clock();
	cout<<"\n"<<fixed<<setprecision(10)<<(ed-st)/1000.0; 
}
