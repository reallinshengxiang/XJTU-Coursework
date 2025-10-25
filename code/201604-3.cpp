#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1010;
ll p,cnt,num,len,pos[3],flag[N],tt,f;
string ss,s[N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p;
	cin>>ss;
	ss=ss+"/";
	for(ll i=0; i<ss.size(); i++)
	{
		if(ss[i]=='/')
		{
			cnt++;
			if(cnt==1) pos[1]=i;
			else
			{
				pos[0]=i;
				num++;
				s[num]=ss.substr(pos[1]+1,pos[0]-pos[1]-1);
				pos[1]=pos[0];
			}
		}
	}
	cin.get();
	while(p--)
	{
		cin>>ss;
		if(ss[ss.size()-1]!='/') ss=ss+"/";
		if(ss[0]!='/') ss="/"+ss;
		memset(flag,0,sizeof(flag));
		cnt=len=0;
		for(ll i=0; i<ss.size(); i++)
		{
			if(ss[i]=='/')
			{
				cnt++;
				if(cnt==1) pos[1]=i;
				else
				{
					pos[0]=i;
					len++;
					a[len]=ss.substr(pos[1]+1,pos[0]-pos[1]-1);
					pos[1]=pos[0];
				}
			}
		}
		deque<string> dq;
		tt=num;
		f=0;
		for(ll i=1;i<=num;i++) dq.push_back(s[i]);
        for(ll i=1;i<=len;i++)
        {
        	if(a[i]=="..") 
			{
				if(!dq.empty()) 
				{
					dq.pop_back(),tt--;
					if(tt<num) f=1;
				}
			}
			else if(a[i]!=""&&a[i]!=".") 
			{
				if(dq.empty()) dq.push_back(a[i]),tt++; 
				else if(a[i]!=dq.back())  dq.push_back(a[i]),tt++;  
			}   	
		}
		if(f==0) 
		{
			for(ll i=1;i<=num;i++) dq.pop_front();
		}
		if(dq.empty()) cout<<"/";
		while(!dq.empty())
		{
			cout<<"/"<<dq.front();
			dq.pop_front(); 
		}
        cout<<"\n";
	}
	return 0;
}
