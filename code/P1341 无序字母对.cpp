#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll g[N][N],degree[N],n,cnt,num,st,ans[N*N],a[N];
string s;
void dfs(ll x)
{
	for(ll i=1;i<=58;i++)
	{
		if(g[x][i])
		{
			g[x][i]=g[i][x]=0;
			dfs(i);
			
		}
	}
	cnt++;
	ans[cnt]=x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	st=58;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
	    ll x=s[0]-'A'+1;
	    ll y=s[1]-'A'+1;
	    st=min(st,min(x,y));
	    degree[x]++;
	    degree[y]++;
	    g[x][y]++;
	    g[y][x]++;
	}
	num=0;
	for(ll i=1;i<=58;i++)
	{
		if(degree[i]%2)
		{
			num++;
			a[num]=i;
		}
	}
	if(num==0) dfs(st);
	else if(num==2)  dfs(a[1]);
	else
	{
		cout<<"No Solution";
		return 0;
	}
	for(ll i=cnt;i>=1;i--) cout<<char(ans[i]-1+'A');
	return 0;
}
