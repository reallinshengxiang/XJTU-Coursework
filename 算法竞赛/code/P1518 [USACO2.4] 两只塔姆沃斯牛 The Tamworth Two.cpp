#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y,towards;
};
point p1,p2;
ll t,a[12][12],vis[12][12][5][12][12][5];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=10;i++)
	{ 
	    cin>>s;
		for(ll j=1;j<=10;j++)
		{
			if(s[j-1]=='*') a[i][j]=0;
			else if(s[j-1]=='.') a[i][j]=1;
			else if(s[j-1]=='F')
			{
				a[i][j]=1;
				p1.x=i;
				p1.y=j;
				p1.towards=0;
			}
			else if(s[j-1]=='C')
			{
				a[i][j]=1;
				p2.x=i;
				p2.y=j;
				p2.towards=0;
			}
		}
	}
	while(1)
	{
		t++;
		if(p1.towards==0&&a[p1.x-1][p1.y]) p1.x--;
		else if(p1.towards==1&&a[p1.x][p1.y+1]) p1.y++;
		else if(p1.towards==2&&a[p1.x+1][p1.y]) p1.x++;
		else if(p1.towards==3&&a[p1.x][p1.y-1]) p1.y--;
		else p1.towards=(p1.towards+1)%4;
		if(p2.towards==0&&a[p2.x-1][p2.y]) p2.x--;
		else if(p2.towards==1&&a[p2.x][p2.y+1]) p2.y++;
		else if(p2.towards==2&&a[p2.x+1][p2.y]) p2.x++;
		else if(p2.towards==3&&a[p2.x][p2.y-1]) p2.y--;
		else p2.towards=(p2.towards+1)%4;
		vis[p1.x][p1.y][p1.towards][p2.x][p2.y][p2.towards]++;
		if(vis[p1.x][p1.y][p1.towards][p2.x][p2.y][p2.towards]>=2)
		{
			cout<<0;
			break;
		}
		if(p1.x==p2.x&&p1.y==p2.y)
		{
			cout<<t;
			break;
		}
	}
	return 0;
}
