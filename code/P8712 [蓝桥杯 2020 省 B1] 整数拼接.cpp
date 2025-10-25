#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll p,ans,t,n,k,a[N],len,cnt[22][N];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		s=to_string(a[i]);
		len=s.size();
		t=(k-a[i]%k)%k;
		ans=ans+cnt[len][t];
		p=10;
		for(ll j=1;j<=9;j++)
		{
			cnt[j][p*a[i]%k]++;
			p=p*10;
		}		
	}
	memset(cnt,0,sizeof(cnt));
	for(ll i=n;i>=1;i--)
	{
		s=to_string(a[i]);
		len=s.size();
		t=(k-a[i]%k)%k;
		ans=ans+cnt[len][t];
		p=10;
		for(ll j=1;j<=9;j++)
		{
			cnt[j][p*a[i]%k]++;
			p=p*10;
		}		
	}
	cout<<ans;
	return 0;
}
