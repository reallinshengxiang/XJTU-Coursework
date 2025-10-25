#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=30;
ll a[N][N],n,ans;
void dfs()
{
	for(ll i=1; i<=(1<<n)-1; i++)
	{
		ll x=i,t=0,flag=1;
		memset(a,0,sizeof(a));
		ll sum1=0,sum2=0;
		while(x!=0)
		{
			t++;
			a[1][t]=x%2;
			if(x%2) sum1++;
			x=x/2;
		}
		sum2=n-sum1;
		for(ll j=2; j<=n; j++)
		{
			for(ll k=1; k<=n-j+1; k++)
			{
				if(a[j-1][k]==a[j-1][k+1])
				{
					a[j][k]=1;
					sum1++;
				}
				else sum2++;
			}
			if(sum1>(n+1)*n/4||sum2>(n+1)*n/4)
			{
				flag=0;
				break;
			}
		}
		if(flag==1&&sum1==sum2) ans++;
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	clock_t start_time, end_time,st;
	start_time = clock();
	srand(time(0));
	for(ll i=1;i<=35;i++)
	{
		n=i;
		st=clock();
		if(((n+1)*n/2)%2)
		{
			cout<<i<<"     0\n";
			continue;
		}
		ans=0;
		dfs();
		end_time=clock();
		cout<<i<<"    "<<ans<<"    Total time: "<<(double)(end_time-st)/CLOCKS_PER_SEC<<"s"<<"\n";
		
	}
    end_time=clock();
    cout<< "\nTotal time: "<<(double)(end_time-start_time)/CLOCKS_PER_SEC<<"s"<< std::endl;
	return 0;
}
