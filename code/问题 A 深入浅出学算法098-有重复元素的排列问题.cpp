#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[30],n,t,ans;
char b[550],ch;
void dfs(ll step)
{
	for(ll i=0;i<=25;i++)
	{
		if(a[i])
		{
			b[step]='a'+i;
			a[i]--;
			if(step==n)
			{
				ans++;
				for(ll k=1;k<=n;k++) cout<<b[k];
				cout<<"\n";
			}
			else dfs(step+1);
			a[i]++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>ch;
		t=ch-'a';
		a[t]++;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
