#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2525;
struct yh{
	ll DN,num;
	map<ll,ll> mp,flag;
};
yh a[N];
ll n,m;
string s;
bool cmp(yh x,yh y)
{
	if(x.DN<y.DN) return 1;
	return 0; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].DN>>a[i].num;
		for(ll j=1;j<=a[i].num;j++) 
		{
			ll x,y;
			cin>>x>>y;
			a[i].mp[x]=y;
			a[i].flag[x]=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	cin>>m;
	while(m--)
	{
		cin>>s;
		ll ff=0,pp[2525];
		memset(pp,0,sizeof(pp));
		for(ll i=0;i<s.size();i++)
		{
			if(s[i]=='(') ff++,pp[ff]=i;
		}
		if(ff==0) 
		{
			ll pos=0,num1=0,num2=0;
			for(ll i=0;i<s.size();i++)
			{
				if(!(s[i]>='0'&&s[i]<='9'))
				{
					pos=i;
					break;
				}
			}
			for(ll i=0;i<pos;i++) num1=num1*10+s[i]-'0';
			for(ll i=pos+1;i<s.size();i++) num2=num2*10+s[i]-'0';
			if(s[pos]==':')
			{
				for(ll i=1;i<=n;i++)
				{
					if(a[i].flag[num1]&&a[i].mp[num1]==num2) cout<<a[i].DN<<" ";
				}
			}
			else 
			{
				for(ll i=1;i<=n;i++)
				{
					if(a[i].flag[num1]&&a[i].mp[num1]!=num2) cout<<a[i].DN<<" ";
				}
			}
			cout<<"\n";
		}
		if(ff==2)
		{
			if(s[0]=='&')
			{
				ll pos1=0,pos2=0,num1=0,num2=0,num3=0,num4=0;
				for(ll i=pp[1]+1;i<=pp[2]-2;i++) 
				{
					if(!(s[i]>='0'&&s[i]<='9'))
					{
						pos1=i;
					    break;
					}
				}
				for(ll i=pp[1]+1;i<pos1;i++) num1=num1*10+s[i]-'0';
			    for(ll i=pos1+1;i<=pp[2]-2;i++) num2=num2*10+s[i]-'0';
			    for(ll i=pp[2]+1;i<s.size()-1;i++) 
				{
					if(!(s[i]>='0'&&s[i]<='9'))
					{
						pos2=i;
					    break;
					}
				}
				for(ll i=pp[2]+1;i<pos2;i++) num3=num3*10+s[i]-'0';
			    for(ll i=pos2+1;i<=s.size()-2;i++) num4=num4*10+s[i]-'0';
			    for(ll i=1;i<=n;i++)
			    {
			    	if(s[pos1]==':'&&a[i].flag[num1]&&a[i].mp[num1]==num2&&s[pos2]==':'&&a[i].flag[num3]&&a[i].mp[num3]==num4) cout<<a[i].DN<<" ";
			    	else if(s[pos1]==':'&&a[i].flag[num1]&&a[i].mp[num1]==num2&&s[pos2]=='~'&&a[i].flag[num3]&&a[i].mp[num3]!=num4) cout<<a[i].DN<<" ";
			    	else if(s[pos1]=='~'&&a[i].flag[num1]&&a[i].mp[num1]!=num2&&s[pos2]==':'&&a[i].flag[num3]&&a[i].mp[num3]==num4) cout<<a[i].DN<<" ";
			    	else if(s[pos1]=='~'&&a[i].flag[num1]&&a[i].mp[num1]!=num2&&s[pos2]=='~'&&a[i].flag[num3]&&a[i].mp[num3]!=num4) cout<<a[i].DN<<" ";	
				}
			}
			else 
			{
				ll pos1=0,pos2=0,num1=0,num2=0,num3=0,num4=0;
				for(ll i=pp[1]+1;i<=pp[2]-2;i++) 
				{
					if(!(s[i]>='0'&&s[i]<='9'))
					{
						pos1=i;
					    break;
					}
				}
				for(ll i=pp[1]+1;i<pos1;i++) num1=num1*10+s[i]-'0';
			    for(ll i=pos1+1;i<=pp[2]-2;i++) num2=num2*10+s[i]-'0';
			    for(ll i=pp[2]+1;i<s.size()-1;i++) 
				{
					if(!(s[i]>='0'&&s[i]<='9'))
					{
						pos2=i;
					    break;
					}
				}
				for(ll i=pp[2]+1;i<pos2;i++) num3=num3*10+s[i]-'0';
			    for(ll i=pos2+1;i<=s.size()-2;i++) num4=num4*10+s[i]-'0';
			    for(ll i=1;i<=n;i++)
			    {
			    	if(s[pos1]==':'&&a[i].flag[num1]&&a[i].mp[num1]==num2)   cout<<a[i].DN<<" ";
			    	else if(s[pos2]==':'&&a[i].flag[num3]&&a[i].mp[num3]==num4) cout<<a[i].DN<<" ";
			    	else if(s[pos1]=='~'&&a[i].flag[num1]&&a[i].mp[num1]!=num2) cout<<a[i].DN<<" ";
			    	else if(s[pos2]=='~'&&a[i].flag[num3]&&a[i].mp[num3]!=num4) cout<<a[i].DN<<" ";
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}
