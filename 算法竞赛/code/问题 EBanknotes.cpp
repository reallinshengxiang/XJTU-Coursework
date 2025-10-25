#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,t,cnt,b[220],f[20020],w[5050],v[5050],c,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)  cin>>b[i];
	for(ll i=1;i<=n;i++)
	{
		cin>>c;
		t=1;
		x=c;
		while(x>=t)
		{
			cnt++;
			w[cnt]=t;
			v[cnt]=b[i]*t;
			x=x-t;
			t=t*2;
		}
		if(x!=0)
		{
			cnt++;
		    w[cnt]=x;
		    v[cnt]=b[i]*x;
		}
	}
	memset(f,127,sizeof(f));
	cin>>k;
	f[0]=0;
	for(ll i=1;i<=cnt;i++)
	{
		for(ll j=k;j>=v[i];j--)	f[j]=min(f[j],f[j-v[i]]+w[i]);
	}
	cout<<f[k];
	return 0;
}
