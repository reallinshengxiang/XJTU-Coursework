#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct cow{
	ll st,ed,position,id,flag;
};
cow a[50005];
bool cmp1(cow a,cow b)
{
	return a.st<b.st; 
}
bool cmp2(cow a,cow b)
{
	return a.position<b.position;
}
ll n,cnt,x,last,p[50005],s[50005],num;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].st>>a[i].ed;
		a[i].position=i;
		a[i].flag=1;
	}
	sort(a+1,a+n+1,cmp1);
	cnt=0;
	num=0;
    for(ll i=1;i<=n;i++)
    {
    	p[a[i].position]=-1;
    	for(ll j=1;j<=num;j++)
    	{
    		if(a[s[j]].ed<a[i].st)
    		{
    			p[a[i].position]=j;
			}
		}
		if(p[a[i].position]==-1)
		{
			num++;
			s[num]=i;
			p[a[i].position]=num;
		}
		else s[p[a[i].position]]=i;
	}
	cout<<num<<"\n";
	for(ll i=1;i<=n;i++) cout<<p[i]<<"\n";
	return 0;
}
