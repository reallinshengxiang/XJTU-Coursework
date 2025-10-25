#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,a[110],b[110],c[110],d[110];
void print()
{
	ans++;
	if(ans<=3)
	{
		for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}
}
void search(ll step)
{
	ll i=step;
	if(step>n) return;
	for(ll j=1;j<=n;j++)
	{
		if(!b[j]&&!c[i+j]&&!d[i-j+n])
		{
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+n]=1;
			if(step==n) print();
			else search(step+1);
			a[i]=0;
			b[j]=0;
			c[i+j]=0;
			d[i-j+n]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    ans=0;
    search(1);
	cout<<ans;
	return 0;
}


