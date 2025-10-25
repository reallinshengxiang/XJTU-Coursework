#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
ll T,n,f,num[N],x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(num,0,sizeof(num));
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>x;
			for(ll j=0;j<=20;j++)
			{
				if((x>>j)&1) num[j]++;
			}
		}
		f=0;
		for(ll i=20;i>=0;i--)
		{
			if(num[i]%2==0) continue;
			else if(num[i]==1)
			{
				cout<<"1\n";
				f=1;
				break;
			}
			else if((n-num[i])%2==1) 
			{
				cout<<"-1\n",f=1;
				break;
			}
			else if((n-num[i])%2==0) 
			{
				cout<<"1\n",f=1;
				break;
			}
		}
		if(!f) cout<<"0\n";
	}
	return 0;
}

