#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e3+10;
ll n,m,k,a[N],vis[N],pos,flag;
stack<ll> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	while(k--)
	{
		for(ll i=1;i<=n;i++) cin>>a[i];
		pos=1;
		memset(vis,0,sizeof(vis));
		flag=1;
		while(!st.empty()) st.pop();
		for(ll i=1;i<=n&&flag;i++)
		{
			if(!vis[i]&&pos<=n)
			{
				while(a[pos]!=i&&pos<=n)
				{
					vis[a[pos]]=1;
					st.push(a[pos]);
					if(st.size()>=m+1) 
					{
						flag=0;
						break;
					}
					pos++;
				}
				if(a[pos]!=i) flag=0; 
				pos++;
			}
			else if(i==st.top()) st.pop();
			else flag=0;
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	return 0;
}
