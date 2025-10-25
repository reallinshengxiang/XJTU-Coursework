#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1000010;
struct node{
	ll son[75];
};
node t[N];
ll cnt=1,p[N],n,m;
char s[N];
void insert(char *s)
{
	ll now=0;
	for(ll i=0;i<=strlen(s)-1;i++)
	{
		ll ch=s[i]-'0';
		if(t[now].son[ch]==0)
		{
			t[now].son[ch]=cnt;
			cnt++;
		}
		now=t[now].son[ch];
	}
	p[now]++;
	
}
ll find(char *s)
{
	ll now=0,ans=0;
	for(ll i=0;strlen(s)-1;i++)
	{
		ll ch=s[i]-'0';
		if(t[now].son[ch]==0) break;
		now=t[now].son[ch];
		ans=ans+p[now];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		insert(s);
	}
	for(ll i=1;i<=m;i++)
	{
		cin>>s;
		cout<<find(s)<<"\n";
	}
	return 0;
}
