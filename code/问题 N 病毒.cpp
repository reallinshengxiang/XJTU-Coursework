#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e6+10;
struct node{
	ll son[2],end,fail;
};
node t[N];
char str[N];
ll cnt,T,f[N],vis[N],check[N];
void insert(char *s)
{
	ll now=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'0';
		if(t[now].son[ch]==0)
		{
			t[now].son[ch]=cnt;
			cnt++;
		}
		now=t[now].son[ch];
	}
	t[now].end++;
	f[now]=0;
}
void getfail()
{
	queue<ll> q;
	for(ll i=0;i<=1;i++)
	{
		if(t[0].son[i]) q.push(t[0].son[i]);
	}
	while(!q.empty())
	{
		ll now=q.front();
		q.pop();
		for(ll i=0;i<=1;i++)
		{
			if(t[now].son[i]) 
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q.push(t[now].son[i]);
				f[t[now].son[i]]=f[t[now].son[i]]&f[t[t[now].fail].son[i]];
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}		
	}
} 
void dfs(ll now)
{
	if(vis[now])
	{
		cout<<"TAK";
		exit(0);
	}
	if(check[now]||f[now]==0) return;
    vis[now]=check[now]=1;
    dfs(t[now].son[0]);
	dfs(t[now].son[1]);
    vis[now]=0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(t,0,sizeof(t));
	memset(f,1,sizeof(f));
	cnt=1;
	ll n;
	cin>>n;
	while(n--)
	{
		cin>>str;
		insert(str);
	}
	getfail();
	dfs(0);
	cout<<"NIE";
	return 0;
} 
