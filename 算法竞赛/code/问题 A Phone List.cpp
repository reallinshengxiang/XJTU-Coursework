#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
struct node{
	ll son[10],num;
};
node t[N];
ll  cnt=0,vis[N],ans,n,T;
char s[22];
ll insert()
{
	cin>>s;
	ll now=0,len=0,flag=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'0';
		if(t[now].son[ch]!=0) len++;
		if(t[now].son[ch]==0)
		{
		    cnt++;
			t[now].son[ch]=cnt;			
		}
		now=t[now].son[ch];
		if(vis[now]==1) flag=1; 
	}
	if(len==strlen(s)) flag=1;
	vis[now]=1;
	if(flag==1) return 1;
	return 0;
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		cnt=0;
		for(ll i=1;i<=n;i++)  ans=ans+insert();
		if(ans>0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
