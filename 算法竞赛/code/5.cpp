#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll x,y;
	node(){}
	node(ll x,ll y):x(x),y(y){}
};
node nn;
ll a[110][110],vis[110][110],ans;
ll dx[4]={0,0,1,-1};
ll dy[4]={1,-1,0,0};
string s;
void search(ll x,ll y)
{
	vis[x][y]=1;
	deque<node> q;
	q.push_back(node(x,y));
	ll sum=1;
	while(!q.empty())
	{
		nn=q.front();
		q.pop_front();
		for(ll i=0;i<=3;i++)
		{
			ll px=nn.x+dx[i];
			ll py=nn.y+dy[i];
			if(1<=px&&px<=30&&1<=py&&py<=60&&a[px][py]&&!vis[px][py])
			{
				q.push_back(node(px,py));
				sum++;
				vis[px][py]=1;
			}
		}
	}
	ans=max(ans,sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    for(ll i=1;i<=30;i++)
    {
    	cin>>s;
    	ll t=0;
    	while(!(s[t]=='0'||s[t]=='1')) t++;
    	for(ll j=t;j<=t+59;j++) a[i][j-t+1]=s[j]-'0';
	}
	cout<<"\n";
	for(ll i=1;i<=30;i++)
	{
		for(ll j=1;j<=60;j++) cout<<a[i][j];
		cout<<"\n";
	} 
	for(ll i=1;i<=30;i++)
	{
		for(ll j=1;j<=60;j++)
		{
			if(!vis[i][j]&&a[i][j]) search(i,j);
		}
	}
	cout<<ans;
	return 0;
}
