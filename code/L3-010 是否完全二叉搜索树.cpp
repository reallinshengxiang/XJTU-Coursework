#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=22;
ll vis[N][1<<N],t[N][1<<N],n,posx,posy,num,sum,step,x,flag;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>x;
		posx=posy=1;
		while(vis[posx][posy])
		{
			if(x>t[posx][posy]) 
			{
				posx++;
				posy=posy*2-1;
			}
			else
			{
				posx++;
				posy=posy*2;
			}
		//	cout<<posx<<" "<<posy<<"  "<<t[posx][posy]<<" "<<vis[posx][posy]<<"\n";
		}
		t[posx][posy]=x;
		vis[posx][posy]=1;
	//	cout<<posx<<" "<<posy<<" "<<x<<"\n";
	}
	num=n;
	sum=1;
	step=1;
	ll cnt=0;
	while(1)
	{
		for(ll i=1;i<=sum;i++)
		{
			if(vis[step][i]!=1) 
			{
				flag=1;
				continue;
			}
			cnt++;
	//		cout<<step<<" "<<i<<"  "<<cnt<<"  "<<sum<<"  "<<num<<"\n";
			if(cnt==n) 
			{
				cout<<t[step][i];
				break;
			}
			else cout<<t[step][i]<<" ";
		}
		num=n-cnt;
		sum=sum*2;
		step++; 
		if(cnt>=n) break;
	//	cout<<step<<"      "<<cnt<<"  "<<sum<<"  "<<num<<"\n";
	}
	if(flag) cout<<"\nNO";
	else cout<<"\nYES";
	return 0;
}
