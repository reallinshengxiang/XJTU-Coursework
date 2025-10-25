#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
struct node{
	ll len,h;
};
node a[N];
ll sum[N][N],n,m,ans,xx;
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			cin>>ch;
			if(ch=='F') sum[i][j]=sum[i-1][j]+1;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		stack<node> st;
		a[1].h=sum[i][1];
		a[1].len=1;
		st.push(a[1]);
		for(ll j=2;j<=m+1;j++)
		{
			xx=0;			
			while(!st.empty()&&sum[i][j]<=st.top().h) 
			{
				xx=xx+st.top().len;
				ans=max(ans,xx*st.top().h);
				st.pop();
			}
			a[i].h=sum[i][j];
			a[i].len=xx+1;
			st.push(a[i]);
		}
	}
	cout<<ans*3;
	return 0;
}
