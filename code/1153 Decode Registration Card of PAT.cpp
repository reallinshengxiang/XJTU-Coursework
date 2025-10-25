#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e4+10;
struct record{
	string term[5],s;
	ll val;
	bool operator < (const record &a)
	{
		if(s<a.s) return 1;
		return 0;
	}
};
struct Ans{
	string site;
	ll num;
	bool operator < (const Ans &a)
	{
		if(num>a.num) return 1;
		if(num==a.num&&site<a.site) return 1;
		return 0;
	}
};
record a[N];
Ans ans[N];
string s;
map<string,ll> vis; 
ll n,m,type,x;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s>>x;
		a[i].s=s;
		a[i].term[1]=s.substr(0,1);
		a[i].term[2]=s.substr(1,3);
		a[i].term[3]=s.substr(4,6);
		a[i].term[4]=s.substr(10,3);
		a[i].val=x;
	}
	//sort(a+1,a+n+1);
    for(ll i=1;i<=m;i++)
	{
		cin>>type>>s;
		cout<<"Case "<<i<<": "<<type<<" "<<s<<"\n";
		ll num1=0,num2=0,cnt=0;
		vis.clear();
		for(ll j=1;j<=n;j++)
		{
			if(a[j].term[type]==s) 
			{
				num1++;
				if(type==1) 
				{
					cnt++;
					ans[cnt].site=a[j].s;
					ans[cnt].num=a[j].val;
				}
				else if(type==2) num2=num2+a[j].val;
				else if(type==3) 
				{
					if(!vis[a[j].term[2]])
					{
						cnt++;
						vis[a[j].term[2]]=cnt;
						ans[cnt].site=a[j].term[2];
						ans[cnt].num=1;
					}
					else  ans[vis[a[j].term[2]]].num++;
				}
			}	
		}
		if(!num1) cout<<"NA\n"; 
		else if(type==1)
		{
			sort(ans+1,ans+cnt+1);
			for(ll k=1;k<=cnt;k++) cout<<ans[k].site<<" "<<ans[k].num<<"\n";
		}
		else if(type==2) cout<<num1<<" "<<num2<<"\n";
		else if(type==3)
		{
			sort(ans+1,ans+cnt+1);
			for(ll k=1;k<=cnt;k++) cout<<ans[k].site<<" "<<ans[k].num<<"\n";
		}
	}
	return 0;
}
