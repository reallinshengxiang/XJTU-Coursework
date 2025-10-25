#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll mod=1e4+7;
struct node{
	ll son[26],end,fail;
};
node t[160000];
char s[1100];
ll cnt,f[110][6100],n,m;
void insert(char *s)
{
	ll now=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'A';
		if(t[now].son[ch]==0)
		{
			t[now].son[ch]=cnt;
			cnt++;
		}
		now=t[now].son[ch];
	}
	t[now].end++;
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
		t[now].end=t[now].end|t[t[now].fail].end;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cnt=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		insert(s);
	}
	getfail();
	f[0][0]=1;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=0;j<=cnt-1;j++)
		{
			if(f[i-1][j]==0) continue;
			for(ll k=0;k<=25;k++)  
			{
				if(t[t[j].son[k]].end) continue;
				f[i][t[j].son[k]]=(f[i][t[j].son[k]]+f[i-1][j])%mod;
			}
		}
	}
	ll ans,ans1=0,ans2=1;
	for(ll i=0;i<=cnt-1;i++) ans1=(ans1+f[m][i])%mod;
	for(ll i=1;i<=m;i++) ans2=ans2*26%mod;
	ans=(ans2+mod-ans1)%mod;
	cout<<ans;
	return 0;
}
