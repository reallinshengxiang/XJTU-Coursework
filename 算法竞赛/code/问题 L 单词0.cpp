#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=1e6+10;
struct node{
	ll son[26],end,fail;
};
node t[N];
ll cnt,id[N],f[N],que[N],n;
char s[N];
void insert(ll x,char *s)
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
		f[now]++;
	}
	t[now].end++;
	id[x]=now;
} 
void getfail()
{
	ll head=0,tail=-1;
	for(ll i=0;i<=25;i++)
	{
		if(t[0].son[i]) 
		{
			tail++;
			que[tail]=t[0].son[i];			
		}
	}
	while(head<=tail)
	{
		ll now=que[head];
		head++;
		for(ll i=0;i<=25;i++)
		{
			if(t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				tail++;
				que[tail]=t[now].son[i];
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cnt=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>s;
		insert(i,s);
	}
	getfail();
	for(ll i=cnt-1;i>=1;i--) f[t[que[i]].fail]=f[t[que[i]].fail]+f[que[i]];
	for(ll i=1;i<=n;i++) cout<<f[id[i]]<<"\n";
	return 0; 
}
