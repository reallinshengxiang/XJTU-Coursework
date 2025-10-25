#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=550;
ll a[N][N],px,py,num,n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<a[1][1]<<" ";
	px=1;
	py=1;
	num=1;
	while(1)
	{
		if(num>=n*n) break;
		if(py+1<=n)
		{
			py++;
			cout<<a[px][py]<<" ";
			num++,px++,py--;
		}
		else 
		{
			px++;
			cout<<a[px][py]<<" ";
			num++,px++,py--;
	    }
		if(num>=n*n) break;
		while(px<=n&&py>=1)
		{
			cout<<a[px][py]<<" ";
			num++,px++,py--;
			if(num>=n*n) break;
		}	
		px--,py++;	
		if(px==n)
		{
			py++;
			cout<<a[px][py]<<" ";
			num++,px--,py++;
		}
		else if(py==1)
		{
			px++;
			cout<<a[px][py]<<" ";
			num++,px--,py++;
		}
		if(num>=n*n) break;
		while(px>=1&&py<=n)
		{
			cout<<a[px][py]<<" ";
			num++,px--,py++;
			if(num>=n*n) break;
		}
	//		cout<<"\n"<<px<<" "<<py<<"\n";
		py--,px++;
	}
	return 0;
}
