#include<bits/stdc++.h>
using namespace std;
#define ll long long
string x,y,m;
char yy[10];
map<string,string> mp;
deque<string> dq;
void waya(string x)
{
	for(ll i=0;i<=3;i++) swap(x[i],x[i+4]);
	if(!mp.count(x))
	{
		dq.push_back(x);
		mp[x]=mp[m]+'A';
	}
}
void wayb(string x)
{
	string xx=x;
	for(ll i=1;i<=7;i++) xx[i]=x[i-1];
	xx[0]=x[3];
	xx[4]=x[7];
	if(!mp.count(xx))
	{
		dq.push_back(xx);
		mp[xx]=mp[m]+'B';
	}
}
void wayc(string x)
{
	string xx=x;
	xx[1]=x[5];
	xx[2]=x[1];
	xx[5]=x[6];
	xx[6]=x[2];
	if(!mp.count(xx))
	{
		dq.push_back(xx);
		mp[xx]=mp[m]+'C';
	}
}
void bfs()
{
	if(x==y)
	{
		cout<<0;
		return;
	}
	dq.push_back(x);
	mp[x]="";
	while(!dq.empty())
	{
		m=dq.front();
		dq.pop_front();
		waya(m);
		wayb(m);
		wayc(m);
		if(mp.count(y))
		{
			cout<<mp[y].size()<<"\n"<<mp[y];
			return; 
		}		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>yy[0]>>yy[1]>>yy[2]>>yy[3]>>yy[7]>>yy[6]>>yy[5]>>yy[4];
	y=yy;
	x="12348765";
	bfs();
	return 0;
}
