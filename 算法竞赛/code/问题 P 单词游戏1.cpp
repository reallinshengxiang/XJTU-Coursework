#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n,indegree[30],outdegree[30],f[30];
string s;
ll find_set(ll x)
{
	if(x!=f[x]) f[x]=find_set(f[x]);
	return f[x];
}
void merge(ll x,ll y)
{
	if(find_set(x)!=find_set(y)) f[find_set(x)]=find_set(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(ll i=1;i<=26;i++) f[i]=i;
		memset(indegree,0,sizeof(indegree));
		memset(outdegree,0,sizeof(outdegree));
		for(ll i=1;i<=n;i++)
		{
			cin>>s;
			ll st=s[0]-'a'+1;
			ll ed=s[s.size()-1]-'a'+1;
			indegree[st]++;
			outdegree[ed]++;
			merge(st,ed);
		}
		ll cnt=0,cntin=0,cntout=0;
		for(ll i=1;i<=26;i++)
		{
			if(((indegree[i]||outdegree[i])&&f[i]==i)||abs(indegree[i]-outdegree[i])>=2) cnt++;
		};
		if(cnt>=2) 
		{
			cout<<"The door cannot be opened.\n";
			continue;
		}
		for(ll i=1;i<=26;i++)
		{
			if(indegree[i]-outdegree[i]==1) cntin++;
			if(outdegree[i]-indegree[i]==1) cntout++;
		}
		if((cntin==1&&cntout==1)||(cntin==0&&cntout==0)) cout<<"Ordering is possible.\n";
		else cout<<"The door cannot be opened.\n";
	}
	return 0;
}
