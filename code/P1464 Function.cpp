#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=25;
ll vis[N][N][N],f[N][N][N],a,b,c;
ll w(ll a,ll b,ll c)
{	
	if(a<=0||b<=0||c<=0) return 1;
	if(vis[a][b][c]) return f[a][b][c];
	vis[a][b][c]=1;
	if(a>=21||b>=21||c>=21) f[a][b][c]=w(20,20,20);
	else if(a<b&&b<c) f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	return f[a][b][c];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>a>>b>>c)
	{
		if(a==-1&&b==-1&&c==-1) break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
		if(a<=0) a=0;
		if(b<=0) b=0;
		if(c<=0) c=0;		
		if(a>=21) a=21;
		if(b>=21) b=21;
		if(c>=21) c=21;
		cout<<w(a,b,c)<<"\n";
	}
	return 0;
}
