#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct pai{
	ll num,flag;
};
pai x;
deque<pai> q[15];
char ch;
ll a,cnt,aa[15];
void print()
{
	cout<<"\n";
		for(ll i=1;i<=13;i++)
		{
			for(ll j=0;j<=3;j++) 
			{
				if(q[i][j].num==1) cout<<"A"<<" ";
				else if(q[i][j].num==0) cout<<"-1 ";
				else if(q[i][j].num==10)  cout<<"0"<<" ";
				else if(q[i][j].num==11)  cout<<"J"<<" ";
				else if(q[i][j].num==12)  cout<<"Q"<<" ";
				else if(q[i][j].num==13)  cout<<"K"<<" ";
				else cout<<q[i][j].num<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=13;i++)
	{
		for(ll j=1;j<=4;j++)
		{
			cin>>ch;
			x.flag=0;
			if(ch>='2'&&ch<='9')  x.num=ch-'0';
			else if(ch=='A') x.num=1;
			else if(ch=='0') x.num=10;
			else if(ch=='J') x.num=11;
			else if(ch=='Q') x.num=12;
			else if(ch=='K') x.num=13;
			q[i].push_back(x);
		}
	}
	cnt=0;
	while(cnt<=3)
	{
		x=q[13].front();
		q[13].pop_front();
		x.flag=1;
		while(x.num!=13)
		{
			q[x.num].push_front(x);
			a=x.num;
			x=q[a].back();
			x.flag=1;
			q[a].pop_back();
		}
		cnt++;		
	}
	for(ll i=1;i<=12;i++)
	{
		for(ll j=0;j<=3;j++)
		{
			if(q[i][j].flag)  aa[q[i][j].num]++;
		}
	}
	cnt=0;
	for(ll i=1;i<=12;i++)
	{
		if(aa[i]==4) 	cnt++;
	}
	cout<<cnt;
	return 0;
}
