#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll son[26],num,end;
};
node t[100010];
ll N,cnt;
char ch;
string s;
void insert(string s)
{
	ll now=0;
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
	t[now].end++;
}
ll find(string s)
{
	ll now=0;
	for(ll i=0;s[i];i++)
	{
		ll ch=s[i]-'a';
		if(t[now].son[ch]==0) return 0;
		now=t[now].son[ch];
	}
	return t[now].end;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	while(N--)
	{
		cin>>ch;
		if(ch=='I')
		{
			cin>>s;
			insert(s);
		}
		else if(ch=='Q')
		{
			cin>>s;
			cout<<find(s)<<"\n";
		}
	}
	return 0;
}
