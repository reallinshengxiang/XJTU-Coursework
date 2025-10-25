#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
struct node{
	ll son[10];
};
node t[N];
ll cnt=1,vis[N];
ll insert(char *s)
{
	ll now=0,len=0,flag=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'0';
		if(t[now].son[ch]) len++;
		if(t[now].son[ch]==0)
		{
			t[now].son[ch]=cnt;
			cnt++;
		}
		now=t[now].son[ch];
		if(vis[now]) flag=1;
	}
	if(len==strlen(s)) flag=1;
	vis[now]=1;
	if(flag==1) return 1;
	return 0;
}
char s[22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll tt=0,ans=0;
	while(cin>>s)
	{		
		if(s[0]=='9')
		{
			tt++;
			if(ans==0) cout<<"Set "<<tt<<" is immediately decodable\n";
			else cout<<"Set "<<tt<<" is not immediately decodable\n";
			memset(t,0,sizeof(t));
			memset(vis,0,sizeof(vis));
			cnt=1;
			ans=0;
		}
		ans=ans+insert(s);		
	}
	return 0;
}
