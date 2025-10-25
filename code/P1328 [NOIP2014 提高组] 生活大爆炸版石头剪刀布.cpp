#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=220;
ll cmp[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}},ans1,ans2,n,na,nb,a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>na>>nb;
	for(ll i=0;i<=na-1;i++) cin>>a[i];
	for(ll i=0;i<=nb-1;i++) cin>>b[i];
	for(ll i=0;i<=n-1;i++)
	{
		ans1=ans1+cmp[a[i%na]][b[i%nb]];
		ans2=ans2+cmp[b[i%nb]][a[i%na]];
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
