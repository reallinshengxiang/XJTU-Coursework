#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	string s;
	ll step;
	node(){}
	node(string s,ll step):s(s),step(step){}
};
node p;
queue<node> que;
string s1,s2,a[11],b[11],s,ss;
ll cnt,pos;
map<string,ll> mp;
void bfs()
{
	que.push(node(s1,0));
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		if(p.step>=11)
		{
			cout<<"NO ANSWER!";
			return;
		}
	    if(p.s==s2) 
	    {
	    	cout<<p.step;
	    	return;
		}
		if(mp[p.s]==1) continue;
		mp[p.s]=1;
		for(ll i=1;i<=cnt;i++)
		{
			s=p.s;
			while(1)
			{
				pos=s.find(a[i]);
			    if(pos<0||pos>=s.size()) break; 
			    ss=p.s;
			    ss.replace(pos,a[i].size(),b[i]);
			    que.push(node(ss,p.step+1));
			    s[pos]='~';
			}
			
		}
	}
	if(mp[s2]!=1) cout<<"NO ANSWER!";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s1>>s2;
	cnt=1;
	while(cin>>a[cnt]>>b[cnt]) cnt++;
	cnt--;
	if(cnt==0&&s1!=s2)
	{
		cout<<"NO ANSWER!";
		return 0;
	}
	bfs();
	return 0;
}
