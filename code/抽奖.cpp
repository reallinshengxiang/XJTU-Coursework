#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll n,ans,a[N],b[N],c[N],m,d[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++) cin>>b[i];
	for(ll i=1;i<=n;i++) cin>>c[i];
	cin>>m;
	ll pos1=1,pos2=1,pos3=1;
	while(m--)
	{
		ll x1,x2,x3;
		cin>>x1>>x2>>x3;
		pos1=(pos1+x1-1)%n+1;
		pos2=(pos2+x2-1)%n+1;
		pos3=(pos3+x3-1)%n+1;
		ll num=0;
		d[1]=a[pos1];
		d[2]=b[pos2];
		d[3]=c[pos3];
		if(d[1]==d[2]&&d[2]==d[3]) num=max(num,(ll)200);
		if(d[1]==d[2]||d[2]==d[3]||d[1]==d[3]) num=max(num,(ll)100);
	//	if(d[1]==d[2]+1&&d[1]==d[3]+2) num=max(num,(ll)200);
		if(d[1]==d[2]-1&&d[1]==d[3]-2) num=max(num,(ll)200);
		sort(d+1,d+4);
	//	if(d[1]==d[2]+1&&d[1]==d[3]+2) num=max(num,(ll)100);
		if(d[1]==d[2]-1&&d[1]==d[3]-2) num=max(num,(ll)100);
		ans=ans+num;
	}
	cout<<ans;
	return 0;
}
/*
4
3 2 4 1
2 2 2 2
4 3 0 9
3
4 4 4
3 1 1
40 39 2
*/
