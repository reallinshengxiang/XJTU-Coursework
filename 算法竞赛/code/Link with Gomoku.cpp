#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(m%5==0)
		{
			for(ll i=1;i<=n/2*2;i++) 
			{
				for(ll j=1;j<=m/5;j++)
				{
					if(i%2) cout<<"oooox";
					else cout<<"xxxxo";
				}
				cout<<"\n";
			}
			if(n%2==1)
			{
				ll flag=1;
				for(ll i=1;i<=m;i++)
				{
					if(flag)  cout<<"x";
					else cout<<"o";
					flag=!flag;
				}
				cout<<"\n";
			}
		}
		else if(m%5==1)
		{
			for(ll i=1;i<=n/2*2;i++) 
			{
				for(ll j=1;j<=m/5;j++)
				{
					if(i%2) cout<<"oooox";
					else cout<<"xxxxo";
				}
				if(i%2) cout<<"o\n";
				else cout<<"x\n";
			}
			if(n%2==1)
			{
				ll flag=1;
				for(ll i=1;i<=m;i++)
				{
					if(flag)  cout<<"x";
					else cout<<"o";
					flag=!flag;
				}
				cout<<"\n";
			}			
		}
		else if(m%5==2)
		{
			for(ll i=1;i<=n/2*2;i++) 
			{
				for(ll j=1;j<=m/5;j++)
				{
					if(i%2) cout<<"oooox";
					else cout<<"xxxxo";
				}
				if(i%2) cout<<"ox\n";
				else cout<<"xo\n";
			}
			if(n%2==1)
			{
				ll flag=1;
				for(ll i=1;i<=m;i++)
				{
					if(flag)  cout<<"x";
					else cout<<"o";
					flag=!flag;
				}
				cout<<"\n";
			}						
		}
		else if(m%5==3)
		{
			for(ll i=1;i<=n/2*2;i++) 
			{
				if(i%2) cout<<"x";
				else cout<<"o"; 
				for(ll j=1;j<=m/5;j++)
				{
					if(i%2) cout<<"oooox";
					else cout<<"xxxxo";
				}
				if(i%2) cout<<"ox\n";
				else cout<<"xo\n";
			}
			if(n%2==1)
			{
				ll flag=1;
				for(ll i=1;i<=m;i++)
				{
					if(flag)  cout<<"x";
					else cout<<"o";
					flag=!flag;
				}
				cout<<"\n";	
			}					
		}
		else if(m%5==4)
		{
			for(ll i=1;i<=n/2*2;i++) 
			{
				if(i%2) cout<<"ox";
				else cout<<"xo"; 
				for(ll j=1;j<=m/5;j++)
				{
					if(i%2) cout<<"oooox";
					else cout<<"xxxxo";
				}
				if(i%2) cout<<"ox\n";
				else cout<<"xo\n";
			}
			if(n%2==1)
			{
				ll flag=1;
				for(ll i=1;i<=m;i++)
				{
					if(flag)  cout<<"x";
					else cout<<"o";
					flag=!flag;
				}
				cout<<"\n";
			}						
		}
	}
	return 0;
}
