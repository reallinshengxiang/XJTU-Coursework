#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=64*2*1000000;
bitset<N> mp;
ll a,b,c,cnt,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c;
	x=1;
	while(!mp[x]&&cnt<=2e6)
	{
		mp[x]=1;
		x=(x*a+(x%b))%c;
		cnt++;		
	}
	if(cnt<=2e6) cout<<cnt;
	else cout<<"-1";
	return 0;
}
