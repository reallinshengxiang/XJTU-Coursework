#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
struct node{
	ll son[26],flag,ans,fail;
};
node t[N];
ll cnt,sum[N],n,idx[N],val[N];
void insert(char *s,ll id)
{
	ll now=1;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'a';
		if(t[now].son[ch]==0)
		{
			cnt++;
			t[now].son[ch]=cnt;			
		}
		now=t[now].son[ch];
	}
	if(!t[now].flag) t[now].flag=id;
	mp[id]=t[now].flag;
}
void getfail()
{
	queue<ll> q;
	for(ll i=0;i<=25;i++) t[0].son[i]=1;
	q.push(1);
	while(!q.empty())
	{
		ll now=q.front();
		q.pop();
		ll fail=t[now].fail;
		for(ll i=0;i<=25;i++)
		{
			if(t[now].son[i]) 
			{
				t[now].son[i]=t[fail].son[i];
				continue;
			}
			t[t[now].son[i]].fail=t[fail].son[i];
			in[t[t[now].son[i]].fail]++;
			q.push(t[now].son[i]);
		}
	}
}
ll query(char *s)
{        
    ll ans=0;
    ll now=0;             
    for(ll i=0;s[i];i++)
	{   
        ll ch=s[i]-'a';
        now=t[now].son[ch];
        for(ll j=now;j;j=t[j].fail) val[j]++;
    }
    for(ll i=0;i<=cnt;i++)
    {
    	if(idx[i]) ans=ans+val[i];
	}
    return ans;
}
char ss[N],tt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ss;
	cin>>n;
	cnt=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>tt;
		insert(tt,i);
	}
	getfail();
	cout<<query(ss);
	return 0; 
}
