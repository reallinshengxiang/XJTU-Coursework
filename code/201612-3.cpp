#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
struct quanxian
{
	string category;
	ll level;
};
quanxian pp[N];
struct juese
{
	string role;
	ll num;
	quanxian qx[N];
};
juese rr[N];
struct yonghu
{
	string user;
	quanxian qx[N*N];
	ll num;
};
yonghu uu[N];
string s,cc,name;
ll p,pos,r,x,u,le,q;
map<string,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>p;
	for(ll i=1; i<=p; i++)
	{
		cin>>s;
		pos=s.size();
		for(ll j=0; j<s.size(); j++)
		{
			if(s[j]==':')
			{
				pos=j;
				break;
			}
		}
		if(pos==s.size()) pp[i].category=s;
		else
		{
			pp[i].category=s.substr(0,pos);
			for(ll j=pos+1; j<s.size(); j++) pp[i].level=pp[i].level*10+(s[j]-'0');
		}
	}
	//for(ll i=1;i<=p;i++) cout<<pp[i].category<<" "<<pp[i].level<<"\n";
	cin>>r;
	for(ll i=1; i<=r; i++)
	{
		cin>>rr[i].role>>rr[i].num;
		for(ll cnt=1; cnt<=rr[i].num; cnt++)
		{
			cin>>s;
			pos=s.size();
			for(ll j=0; j<s.size(); j++)
			{
				if(s[j]==':')
				{
					pos=j;
					break;
				}
			}
			if(pos==s.size()) rr[i].qx[cnt].category=s;
			else
			{
				rr[i].qx[cnt].category=s.substr(0,pos);
				for(ll j=pos+1; j<s.size(); j++) rr[i].qx[cnt].level=rr[i].qx[cnt].level*10+(s[j]-'0');
			}
		}
	}
	/*	for(ll i=1;i<=r;i++)
		{
			cout<<rr[i].num<<"\n";
			for(ll j=1;j<=rr[i].num;j++) cout<<rr[i].qx[j].category<<"  "<<rr[i].qx[j].level<<"\n";
		}*/
	cin>>u;
	for(ll i=1; i<=u; i++)
	{
		cin>>uu[i].user>>x;
		mp[uu[i].user]=i;
		for(ll ii=1; ii<=x; ii++)
		{
			cin>>s;
			for(ll k=1;k<=r;k++)
			{
				if(rr[k].role==s)
				{
					for(ll j=1;j<=rr[k].num;j++)
					{
						uu[i].qx[++uu[i].num].category=rr[k].qx[j].category;
						uu[i].qx[uu[i].num].level=rr[k].qx[j].level;
					}
					break;
				}				
			}
		}
	}
    /*	for(ll i=1;i<=u;i++)
	{
		cout<<uu[i].user<<" "<<uu[i].num<<"\n";
		for(ll j=1;j<=uu[i].num;j++) cout<<uu[i].qx[j].category<<" "<<uu[i].qx[j].level<<"\n";
	}*/
	cin>>q;
	while(q--)
	{
		cin>>name>>s;
		pos=s.size();
        le=0;
		for(ll j=0; j<s.size(); j++)
		{
			if(s[j]==':')
			{
				pos=j;
				break;
			}
		}
		if(pos==s.size()) cc=s;
		else
		{
			cc=s.substr(0,pos);
			for(ll j=pos+1; j<s.size(); j++) le=le*10+(s[j]-'0');
		}
		if(!mp[name]) cout<<"false\n";
		else if(le!=0)
		{
			ll xx=mp[name];
			ll flag=0;
			for(ll j=1;j<=uu[xx].num;j++)
			{
				if(uu[xx].qx[j].level>=le&&uu[xx].qx[j].category==cc) 
				{
					flag=1;
					break;
				}
			}
			if(flag) cout<<"true\n";
			else cout<<"false\n";
		}
		else
		{
			ll flag=0,maxx=0;
			ll xx=mp[name];
			for(ll j=1;j<=uu[xx].num;j++)
			{
				if(uu[xx].qx[j].level>=le&&uu[xx].qx[j].category==cc) 
				{
					flag=1;
					maxx=max(maxx,uu[xx].qx[j].level);
				}
			}
			if(!flag) cout<<"false\n";
			else if(maxx==0) cout<<"true\n";
			else cout<<maxx<<"\n";
		}
	}
	return 0;
}
