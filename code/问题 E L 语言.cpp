#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1024*1024+10;
struct node{
	ll son[26],end;
}; 
node t[21*11];
ll cnt=1,len,n,m,f[N];
char s[N];
void insert(char* s)
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
	t[now].end=1;
}
void search(ll x)
{
	ll now=0;
	for(ll i=x;s[i];i++)
	{
		ll ch=s[i]-'a';
		if(!t[now].son[ch]) break;
		now=t[now].son[ch];
		if(t[now].end==1) f[i]=1;
	}
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
		memset(f,0,sizeof(f));
		f[0]=1;
		cin>>(s+1);
		len=strlen(s+1);
		for(ll j=0;j<=len;j++) 
		{
			if(f[j]) search(j+1);
		}
		for(ll j=len;j>=0;j--)
		{
			if(f[j]) 
			{
				cout<<j<<"\n";
				break;
			}
		}
	}
	return 0;
} 
