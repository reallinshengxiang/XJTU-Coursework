#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
ll a[N],b[N],c[N],n,pos1,pos2,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) cin>>b[i];
    for(ll i=1;i<=n;i++) cin>>c[i];
    sort(a+1,a+n+1);
    sort(c+1,c+n+1);
    for(ll i=1;i<=n;i++)
    {
    	pos1=lower_bound(a+1,a+n+1,b[i])-(a+1);
    	pos2=upper_bound(c+1,c+n+1,b[i])-c;
    	ans=ans+(n-pos2+1)*pos1;
	}
	cout<<ans;
	return 0;
}
