#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize(2)
const ll N=2e5+10;
ll n,cnt,tt,fa[N],m;
string s1,s2;
map<string,ll> mp;
map<ll,ll> xb,xs,xm,vis;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		string ss1,ss2;
		ll flag1=0,flag2=0,sex;
		if(s2.size()>=4)
		{
			ss1=s2.substr(s2.size()-4,4);
			if(ss1=="sson") flag1=1,s2=s2.substr(0,s2.size()-4);
		}
		if(s2.size()>=7)
		{
			ss2=s2.substr(s2.size()-7,7);
			if(ss2=="sdottir") flag2=1,s2=s2.substr(0,s2.size()-7);
		}
		if(flag1) sex=1;
		else if(flag2) sex=0;
		if(!flag1&&!flag2)
		{
			if(s2[s2.size()-1]=='m') sex=1,s2=s2.substr(0,s2.size()-1);
			else sex=0,s2=s2.substr(0,s2.size()-1);
		}
		if(!mp[s1])
		{
			cnt++;
			mp[s1]=cnt;
		}
		if(!mp[s2])
		{
			cnt++;
			mp[s2]=cnt;
		}
		fa[mp[s1]]=mp[s2];
		xb[mp[s1]]=sex;
		xs[mp[s1]]=mp[s2];
		xm[mp[s2]]=mp[s1];
	//	cout<<mp[s1]<<" "<<fa[mp[s1]]<<"\n";
	}
	cin>>m;
	while(m--)
	{
		string s1,s2,s3,s4;
		cin>>s1>>s2>>s3>>s4;
	//	cout<<mp[s1]<<" "<<mp[s3]<<"\n";
		if(!mp[s1]||!mp[s2]||!mp[s3]||!mp[s4]) cout<<"NA\n";
		else if(xs[mp[s1]]!=mp[s2]||xs[mp[s3]]!=mp[s4]) cout<<"NA\n";
		else if(xb[mp[s1]]==xb[mp[s3]]) cout<<"Whatever\n";
		else
		{
			ll flag=1;
			ll now1=mp[s1],now2=mp[s3];
			vis.clear();
			vis[now1]=1;
		//	cout<<now1<<" ";
			for(ll i=1;i<=3;i++)
			{
				if(now1>0) 
				{
					now1=fa[now1];
					vis[now1]=1;
			//		cout<<now1<<" ";
				}
				else break;		
			}
		//	cout<<"\n"<<now2<<" ";
			if(vis[now2]) flag=0; 
			for(ll i=1;i<=3;i++)
			{
				if(now2>0)
				{
					now2=fa[now2];
					if(vis[now2]&&now2!=0) flag=0;
					//cout<<now2<<" ";
				}				
				else break;
			}
			if(!flag) cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}
