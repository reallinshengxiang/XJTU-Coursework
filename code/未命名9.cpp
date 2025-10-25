#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#pragma GCC optimize(2)
ll a[10][10],cnt;
void print()
{
	for(ll i=1;i<=6;i++)
	{
		for(ll j=1;j<=6;j++) cout<<a[i][j]<<" ";
		cout<<"\n";
	}	
	cout<<"\n";
}
int main()
{
	for(ll ii=1;ii<(1<<36);ii++)
	{
		for(ll i=1;i<=6;i++)
		{
			for(ll j=1;j<=6;j++) a[i][j]=(ii<<(36-(i-1)*6+j))%2;
		}
		/*if(a[1][1]==0) continue;
		if(a[1][3]==0) continue;
		if(a[3][4]==0) continue;
		if(a[5][3]==0) continue;
		if(a[5][6]==0) continue;
		if(a[6][5]==0) continue;
		if(a[1][2]) continue;
		if(a[1][4]) continue;
		if(a[2][4]) continue;
		if(a[3][5]) continue;
		if(a[3][6]) continue;
		if(a[6][2]) continue;*/
		cout<<ii<<"\n";
		print();
	}
}
