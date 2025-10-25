#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2010;
ll sz,last;
struct node
{
	ll son[26],father,len;
};
node t[N<<1];
void newnode(ll length)
{
	sz++;
	t[sz].len=length;
	t[sz].father=-1;
	memset(t[sz].son,0,sizeof(t[sz].son));
}
void init()
{
	sz=-1;
	last=0;
	newnode(0);
}
void insert(ll c)
{
	newnode(t[last].len+1);
	ll p=last,cur=sz;
	while(p!=-1&&!t[p].son[c])
	{
		t[p].son[c]=cur;
		p=t[p].father;
	}
	if(p==-1)	t[cur].father=0;
	else
	{
		ll q=t[p].son[c];
		if(t[q].len==t[p].len+1)  t[cur].father=q;
		else
		{
			newnode(t[p].len+1);
			ll nq=sz;
			memcpy(t[nq].son,t[q].son,sizeof(t[q].son));
			t[nq].father=t[q].father;
			t[cur].father=t[q].father=nq;
			while(p>=0&&t[p].son[c]==q)
			{
				t[p].son[c]=nq;
				p=t[p].father;
			}
		}
	}
	last=cur;
}
char S[N];
ll ans[N][N];
int main()
{
	cin>>S;
	ll n=strlen(S);
	for(ll i=0;i<=n-1;i++)
	{
		init();
		for(ll j=i;j<=n-1;j++)
		{
			insert(S[j]-'a');
			ans[i][j]=ans[i][j-1]+t[last].len-t[t[last].father].len;
		}
	}
    cout<<ans[0][n-1];
	return 0;
}
