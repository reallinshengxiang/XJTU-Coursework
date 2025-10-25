#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=4e5+10;
ll yh[N],opt[N],cnt,tt,a[N],n,q;
string s[N][3],ss[N];
map<string,ll> mp;
string nex(string s)
{
	string ss=s;
	for(ll i=s.size()-1;i>=0;i--)
	{
		if(s[i]==':') continue;
		if(s[i]=='f') ss[i]='0';
		else
		{
			ss[i]=s[i]+1;
		    break;
		}		
	}
	return ss;
}
string pre(string s)
{
	string ss=s;
	for(ll i=s.size()-1;i>=0;i--)
	{
		if(s[i]==':') continue;
		if(s[i]=='0') ss[i]='f';
		else
		{
			if(ss[i]=='A') ss[i]='9';
			else ss[i]=s[i]-1;
		    break;
		}		
	}
	return ss;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=q;i++)
	{
		cin>>opt[i];
		if(opt[i]==1) 
		{
			cin>>yh[i];
			cin>>s[i][1]>>s[i][2];
			cnt++;
			ss[cnt]=s[i][1];
			cnt++;
			ss[cnt]=nex(s[i][1]);
			cnt++;
			ss[cnt]=pre(s[i][1]);
			cnt++;
			ss[cnt]=s[i][2];
			cnt++;
			ss[cnt]=nex(s[i][2]);
			cnt++;
			ss[cnt]=pre(s[i][2]);
		}
		else if(opt[i]==2)
		{
			cin>>s[i][1];
			cnt++;
			ss[cnt]=s[i][1];
		}
		else
		{
			cin>>s[i][1]>>s[i][2];
			cnt++;
			ss[cnt]=s[i][1];
			cnt++;
			ss[cnt]=nex(s[i][1]);
			cnt++;
			ss[cnt]=pre(s[i][1]);
			cnt++;
			ss[cnt]=s[i][2];
			cnt++;
			ss[cnt]=nex(s[i][2]);	
			cnt++;
			ss[cnt]=pre(s[i][2]);
		}
	}
	sort(ss+1,ss+cnt+1);
	tt=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(!mp[ss[i]]) 
		{
			tt++;
			mp[ss[i]]=tt;
		}
	}
	for(ll i=1;i<=q;i++)
	{
		if(opt[i]==2) cout<<a[mp[s[i][1]]]<<"\n";
		else if(opt[i]==1)
		{
			ll flag=1,ff=1;
			for(ll j=mp[s[i][1]];j<=mp[s[i][2]];j++)
			{
				if(a[j]!=yh[i]&&a[j])
				{
					flag=0;
					ff=0;
					break;
				}
				if(a[j]!=yh[i]) ff=0;
			}
			if(flag&&!ff)
			{
				for(ll j=mp[s[i][1]];j<=mp[s[i][2]];j++) a[j]=yh[i];
				cout<<"YES\n";
			}
			else cout<<"NO\n";
		}
		else
		{
			ll flag=1;			
			for(ll j=mp[s[i][1]]+1;j<=mp[s[i][2]];j++)
			{
				if(a[j]!=a[mp[s[i][1]]])
				{
					flag=0;
					break;
				}
			}
			if(flag) cout<<a[mp[s[i][1]]]<<"\n";
			else cout<<"0\n";
		}
	}
	return 0;
}
