#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
struct node{
	ll next,front;
};
node p[N];
ll flag[N],n,m;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(ll i=0;i<=n-1;i++) p[i].next=i+1,p[i].front=i-1;
	for(ll i=1;i<=m;i++)
	{
		for(ll j=0;j<=n-1;j=p[j].next)
		{
			if(flag[j]) continue;
			if(s[j]>s[p[j].next])
			{
				flag[j]=1;
				p[p[j].front].next=p[j].next;
				p[p[j].next].front=p[j].front;
				break;
			}
		}
	}
	for(ll i=0;i<=n-1;i++) 
	{
		if(!flag[i]) cout<<s[i];
	}
	return 0;
}
