#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans,a[100010],f[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1,j=1;i<=n;i++)
	{
		f[a[i]]++;
		while(f[a[i]]>1)
		{
			f[a[j]]--;
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
