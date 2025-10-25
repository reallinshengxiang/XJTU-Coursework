#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct shu{
	ll num,pos;
	bool operator<(const shu x) const 
	{ 
	    return num<x.num;
	}
};
shu a[100010],xx,yy;
set<shu> s;
set<shu>::iterator now,tt,pp;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>a[i].num;
		a[i].pos=i;
	}
	s.insert(a[1]);
	for(ll i=2;i<=n;i++)
	{		
	    s.insert(a[i]);
	    now=s.find(a[i]);
	    tt=now;
	    pp=now;
	    pp++;
	    if(tt!=s.begin()) 	xx=*(--tt);
	    else xx.num=0x3f3f3f3f3f;
	    if(pp!=s.end()) 	yy=*(pp);
        else yy.num=0x3f3f3f3f3f;
	    if(abs(a[i].num-xx.num)<=abs(a[i].num-yy.num)) cout<<abs(a[i].num-xx.num)<<" "<<xx.pos<<"\n";
	    else cout<<abs(a[i].num-yy.num)<<" "<<yy.pos<<"\n";
	    s.insert(a[i]);
	}
	return 0;
} 
