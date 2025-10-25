#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e6+10;
struct node{
	ll son[26],end,fail;
};
node t[N];
ll cnt,n,st[N];
char str[N],s[N],ans[N];
void insert(char *s)
{
	ll now=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'a';
		if(t[now].son[ch]==0)
		{
			t[now].son[ch]=cnt;
			cnt++;
		}
		now=t[now].son[ch];
	}
	t[now].end=strlen(s);
}
void getfail()
{
	queue<ll> q;
	for(ll i=0;i<=25;i++)
	{
		if(t[0].son[i]) q.push(t[0].son[i]);
	}
	while(!q.empty())
	{
		ll now=q.front();
		q.pop();
		for(ll i=0;i<=25;i++)
		{
			if(t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q.push(t[now].son[i]);
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}
void solve()
{
	ll now=0,top=0;
	for(ll i=0;str[i];i++)
	{
		ll ch=str[i]-'a';
		now=t[now].son[ch];
		top++;
		st[top]=now;
		ans[top]=str[i];
		if(t[now].end) 
		{
			top=top-t[now].end;
			now=st[top];
		}
	}
	for(ll i=1;i<=top;i++) cout<<ans[i];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>str;
	cin>>n;
	cnt=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		insert(s);
	}
	getfail();
	solve();
	return 0;
}
