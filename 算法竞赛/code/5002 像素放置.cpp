#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[11][11],b[11][11],cnt;
string s;
ll check(ll nn,ll mm)
{
	 for(ll i=1;i<=nn;i++)
	 {
	 	for(ll j=1;j<=mm;j++)
	 	{
	 		ll sum=0;
	 		for(ll k=max((ll)1,i-1);k<=min(nn+1,i+1);k++)
	 		{
	 			for(ll q=max((ll)1,j-1);q<=min(m,j+1);q++) sum=sum+b[k][q];
			}
			if(sum!=a[i][j]&&a[i][j]!=-1)	return 0;
		}		
     }    
     return 1;
}
void dfs(ll step)
{
	if(step==n+1) return;
	for(ll ii=0;ii<=(1<<m)-1;ii++)
	{
		for(ll jj=0;jj<=m-1;jj++) b[step][jj+1]=((ii>>jj)&1);
		if(check(step-1,m)) dfs(step+1);
	} 
}
void print()
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++) cout<<b[i][j];
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		for(ll j=1;j<=m;j++) 
		{
			if(s[j]>='0'&&s[j]<='9') a[i][j]=s[j]-'0';
			else a[i][j]=-1;
		}
	}
	if(n==1)
	{
		for(ll i=0;i<=(1<<m)-1;i++)
		{
			for(ll j=0;j<=m-1;j++) b[1][j+1]=((i>>j)&1);
			//for(ll k=1;k<=m;k++) cout<<b[1][k];
			//cout<<"\n";
			//cout<<check()<<"\n";
			if(check(n,m))
			{
				for(ll k=1;k<=m;k++) cout<<b[1][k];
				return 0;
			}
		}
	}
	else if(n==2)
	{
		for(ll i=0;i<=(1<<m)-1;i++)
		{
			for(ll j=0;j<=m-1;j++) b[1][j+1]=((i>>j)&1);
            for(ll k=0;k<=(1<<m)-1;k++)
            {
            	for(ll j=0;j<=m-1;j++) b[2][j+1]=((k>>j)&1);
			}
			//for(ll k=1;k<=m;k++) cout<<b[1][k];
			//cout<<"\n";
			//cout<<check()<<"\n";
			if(check(n,m))
			{
				for(ll j=1;j<=n;j++)
				{
					for(ll k=1;k<=m;k++) cout<<b[1][k];
					cout<<"\n";
				}				
				return 0;
			}
		}
	}
	for(ll i=0;i<=(1<<m)-1;i++)
	{
		for(ll j=0;j<=m-1;j++) b[1][j+1]=((i>>j)&1);
        for(ll k=0;k<=(1<<m)-1;k++)
        {
            for(ll j=0;j<=m-1;j++) b[2][j+1]=((k>>j)&1);
            for(ll p=0;p<=(1<<m)-1;p++)
            {
            	for(ll j=0;j<=m-1;j++) b[3][j+1]=((p>>j)&1);
            	cnt++;
			    if(!check(2,m)) continue;
			    cout<<"\n";
			    dfs(4);
			    print();
			}
		}
			//for(ll k=1;k<=m;k++) cout<<b[1][k];
			//cout<<"\n";
			//cout<<check()<<"\n";
		
		if(check(n,m))
		{
			for(ll j=1;j<=n;j++)
			{
				for(ll k=1;k<=m;k++) cout<<b[1][k];
				cout<<"\n";
			}				
			return 0;
		}
	}	
	cout<<cnt;
	return 0;
 } 
