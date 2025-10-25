#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll nex[N],n,m,cnt,a[N];
string p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p;
	n=p.size();
    nex[0]=0;
    nex[1]=0;
    for(ll i=1;i<=n-1;i++)
    {
    	ll j=nex[i];
    	while(j&&p[i]!=p[j]) j=nex[j];
    	if(p[i]==p[j]) nex[i+1]=j+1;
    	else nex[i+1]=0;
	}
	ll j=n;
	while(nex[j])
	{
		cnt++;
		a[cnt]=nex[j];
		j=nex[j];
	}
	cout<<cnt<<"\n";
	for(ll i=cnt;i>=1;i--) cout<<a[i]<<" ";
	return 0;
 } 
