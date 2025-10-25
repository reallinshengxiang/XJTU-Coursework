#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#pragma GCC optimize(2)
ll a[10][10],cnt;
void print()
{
	for(ll i=1;i<=6;i++)
	{
		for(ll j=1;j<=6;j++) cout<<a[i][j];
	}
}
int main()
{
	a[1][1]=a[1][3]=1;
	a[1][6]=1;
	cout<<(1<<30)-1<<"\n";
	for(ll ii=1;ii<(1<<30);ii++)
	{
		for(ll i=2;i<=6;i++)
		{
			for(ll j=1;j<=6;j++) a[i][j]=(ii>>(30-(i-2)*6-j))%2;
		}
		if(a[1][1]==0) continue;
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
		if(a[6][2]) continue;
		//cout<<ii<<"\n";
		ll flag=1;
		for(ll i=1;i<=6;i++)
		{
			ll sum=0;
			for(ll j=1;j<=6;j++) sum=sum+a[i][j];
			if(sum!=3) 
			{
				flag=0;
				break;
			}
		}
		for(ll i=1;i<=6;i++)
		{
			ll sum=0;
			for(ll j=1;j<=6;j++) sum=sum+a[j][i];
			if(sum!=3) 
			{
				flag=0;
				break;
			}
		}
		for(ll i=1;i<=6;i++)
		{
			for(ll j=i+1;j<=6;j++)
			{
				ll ff=1;
				for(ll k=1;k<=6;k++) 
				{
					if(a[i][k]!=a[j][k]) ff=0;
				}
				if(ff)
				{
					flag=0;
					break;
				}
			}
		}
		for(ll i=1;i<=6;i++)
		{
			for(ll j=i+1;j<=6;j++)
			{
				ll ff=1;
				for(ll k=1;k<=6;k++) 
				{
					if(a[k][i]!=a[k][j]) ff=0;
				}
				if(ff)
				{
					flag=0;
					break;
				}
			}
		}
		for(ll i=1;i<=6;i++)
		{
			for(ll j=1;j<=6;j++)
			{
				if(i>=3)
				{
					if(a[i][j]==a[i-1][j]&&a[i-1][j]==a[i-2][j]) 
					{
						flag=0;
						break;
					}
				}
				if(j>=3)
				{
					if(a[i][j]==a[i][j-1]&&a[i][j-1]==a[i][j-2]) 
					{
						flag=0;
						break;
					}
				}
			}
		}
		if(flag) cout<<ii<<"\n",print();
	}
}

/*
1 0 1 0 0 1
0 1 0 0 1 1
1 0 1 1 0 0
0 1 0 1 1 0
0 1 1 0 0 1
1 0 0 1 1 0
*/
/*101001010011101100010110011001100110*/
