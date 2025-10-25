#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e6+10;
struct node{
	ll son[26],end,fail;
};
node t[N];
char str[N];
ll cnt,T;
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
ll query(char *s)
{
	ll ans=0,now=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'a';
		now=t[now].son[ch];
		ll tmp=now;
		while(tmp&&t[tmp].end!=-1)
		{
			ans=ans+t[tmp].end;
			t[tmp].end=-1;
			tmp=t[tmp].fail;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(t,0,sizeof(t));
		cnt=1;
		ll n;
		cin>>n;
		while(n--)
		{
			cin>>str;
			insert(str);
		}
		getfail();
		cin>>str;
		cout<<query(str)<<"\n";
	}
	return 0;
} 
