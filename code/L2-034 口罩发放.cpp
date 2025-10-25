#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=35;
struct peo{
	string name,id;
	ll condition,tim,th,day;
};
peo p[N][N];
ll d,pp,t[N],s[N];
map<string,ll> mp,mpp;
bool cmp(peo x,peo y)
{
	if(x.tim<y.tim) return 1;
	if(x.tim==y.tim&&x.th<y.th) return 1;
	return 0; 
}
bool cmp2(peo x,peo y)
{
	if(x.th<y.th) return 1;
	return 0; 
}
bool check(string s)
{
	if(s.size()!=18) return 1;
	for(ll i=0;i<=17;i++)
	{
		if(!(s[i]>='0'&&s[i]<='9')) return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>d>>pp;
	for(ll i=1;i<=d;i++)
	{
		cin>>t[i]>>s[i];
		for(ll j=1;j<=t[i];j++)
		{
			cin>>p[i][j].name>>p[i][j].id>>p[i][j].condition;
			char ch;			
			ll hh,mm;
			cin>>hh>>ch>>mm;
			p[i][j].tim=hh*60+mm;
			p[i][j].day=i;		
			p[i][j].th=j;
			if(check(p[i][j].id))
			{
				j--;
				t[i]--;				
				continue;
			}	
		}
		sort(p[i]+1,p[i]+t[i]+1,cmp);
		ll num=0;
		for(ll j=1;j<=t[i];j++)
		{
			if(num==s[i]) break;
			if(!mp[p[i][j].id]) 
			{
				num++;
				mp[p[i][j].id]=p[i][j].day;
				cout<<p[i][j].name<<" "<<p[i][j].id<<"\n";
			}
			else if(mp[p[i][j].id]+pp+1<=p[i][j].day) 
			{
				num++;
				mp[p[i][j].id]=p[i][j].day;
				cout<<p[i][j].name<<" "<<p[i][j].id<<"\n";
			} 
		}
	}
	for(ll i=1;i<=d;i++)
	{
		sort(p[i]+1,p[i]+t[i]+1,cmp2);
		for(ll j=1;j<=t[i];j++)
		{
			if(p[i][j].condition&&!mpp[p[i][j].id])
			{
				cout<<p[i][j].name<<" "<<p[i][j].id<<"\n";
				mpp[p[i][j].id]=1;
			}
		}
	}
	return 0;
}
