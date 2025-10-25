#include<bits/stdc++.h>
using namespace std;
#define ll long long
string p;
ll nex[33],plen;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	getline(cin,p);
	plen=p.size();
	nex[0]=nex[1]=0;
	for(ll i=1;i<=plen-1;i++)
	{
		ll j=nex[i];
		while(j&&p[i]!=p[j]) j=nex[j];
		if(p[i]==p[j]) nex[i+1]=j+1;
		else nex[i+1]=0;
	}
	nex[0]=-1;
	for(ll i=0;i<=plen-1;i++) cout<<nex[i]<<" ";
	return 0;
}
