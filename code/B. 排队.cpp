#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct student{
	ll left,right;
};
student stu[100010],t;
ll n,m;
void print()
{
	for(ll i=stu[0].right;i!=-1;i=stu[i].right) cout<<i<<" ";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	stu[0].left=0;
	stu[0].right=1;
	for(ll i=1;i<=n;i++)
	{
		stu[i].left=i-1;
		stu[i].right=i+1;
	}
	stu[n].right=-1;
	while(m--)
	{
		char ch;
		cin>>ch;
		if(ch=='L')
		{
			ll x,y;
			cin>>x>>y;
			if(stu[x].right==-1) 
			{
				stu[stu[x].left].right=-1;				
			}
			else
			{
				stu[stu[x].left].right=stu[x].right;
			    stu[stu[x].right].left=stu[x].left;
			}			
			stu[stu[y].left].right=x;
			stu[x].left=stu[y].left;
			stu[x].right=y;
			stu[y].left=x;
			
		}
		else if(ch=='R')
		{
			ll x,y;
			cin>>x>>y;
			stu[stu[x].left].right=stu[x].right;
			if(stu[x].right!=-1) stu[stu[x].right].left=stu[x].left;
			if(stu[y].right==-1)
			{
				stu[y].right=x;
				stu[x].right=-1;
				stu[x].left=y;
			}
			else
			{
				stu[stu[y].right].left=x;
				stu[x].right=stu[y].right;
				stu[y].right=x;
				stu[x].left=y;
			}
		}
	}
	print();
	return 0; 
}
