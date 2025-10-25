#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
map<ll,ll> mp;
ll n,m,x,nn,cnt,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(cin>>x) 
	{
		cnt++;
		a[cnt]=x;
		if(!mp[x]) mp[x]=1;
		else nn=x; 
	}
	sort(a+1,a+cnt+1);
	for(ll i=a[1];i<=a[cnt];i++)
	{
		if(!mp[i])
		{
			m=i;
			break;
		}
	}
	cout<<m<<" "<<nn;
	return 0;
}
