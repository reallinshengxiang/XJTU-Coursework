#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[10],x,d[10][10],flag,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	d[1][2]=d[2][1]=1;
	d[1][4]=d[4][1]=1;
	d[1][5]=d[5][1]=1;
	d[2][3]=d[3][2]=1;
	d[3][4]=d[4][3]=1;
	d[3][7]=d[7][3]=1;
	d[4][7]=d[7][4]=1;
	d[4][5]=d[5][4]=1;
	d[5][6]=d[6][5]=1;
	d[6][7]=d[7][6]=1;
	for(ll i=1;i<(1<<7);i++)
	{
		x=i;
		while(x!=0)
		{
			for(ll j=1;j<=7;j++)
			{
				a[j]=x%2;
				x=x/2;
			}
			
		}
		flag=1;
		for(ll i=1;i<=7;i++)
		{
			for(ll j=1;j<=7;j++)
			{
				if(i==j) continue;
				if(a[i]&&a[j]&&d[i][j]) continue;
				if(a[i]&&a[j]&&!d[i][j])
				{
					ll ff=0;
					for(ll k=1;k<=7;k++)
					{
						if(d[i][k]&&d[k][j]) ff=1;
					}
					flag=ff;
				}
				if(flag==0) break;
			}
		 } 
		 if(flag) 
		 {
		 	ans++;
		 	for(ll j=1;j<=7;j++) cout<<a[j]<<" ";
			cout<<"\n";
		 }
	}
	cout<<ans;
	return 0;
}
