#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3600*24+10;
struct tim{
	ll sthour,stmin,stsec,st,edhour,edmin,edsec,ed;
};
tim t[N];
ll n;
string s;
bool cmp(tim a,tim b)
{
	if(a.st<b.st) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin.get();
	for(ll i=1;i<=n;i++)
	{
		getline(cin,s);
		t[i].sthour=(s[0]-'0')*10+(s[1]-'0');
		t[i].stmin=(s[3]-'0')*10+(s[4]-'0');
		t[i].stsec=(s[6]-'0')*10+(s[7]-'0');
		t[i].st=t[i].sthour*3600+t[i].stmin*60+t[i].stsec;
		t[i].edhour=(s[11]-'0')*10+(s[12]-'0');
		t[i].edmin=(s[14]-'0')*10+(s[15]-'0');
		t[i].edsec=(s[17]-'0')*10+(s[18]-'0');
		t[i].ed=t[i].edhour*3600+t[i].edmin*60+t[i].edsec;
	//	cout<<t[i].sthour<<" "<<t[i].stmin<<" "<<t[i].stsec<<"        "<<t[i].edhour<<" "<<t[i].edmin<<" "<<t[i].edsec<<"\n";
	}
	sort(t+1,t+n+1,cmp);
	t[0].ed=0;
	t[n+1].sthour=23;
	t[n+1].stmin=59;
	t[n+1].stsec=59;
	t[n+1].st=23*3600+59*60+59;
	for(ll i=1;i<=n+1;i++)
	{
		if(t[i-1].ed!=t[i].st)
		{
			if(t[i-1].edhour<=9) cout<<"0";
			cout<<t[i-1].edhour<<":";
			if(t[i-1].edmin<=9) cout<<"0";
			cout<<t[i-1].edmin<<":";
			if(t[i-1].edsec<=9) cout<<"0";
			cout<<t[i-1].edsec<<" - ";
			if(t[i].sthour<=9) cout<<"0";
			cout<<t[i].sthour<<":";
			if(t[i].stmin<=9) cout<<"0";
			cout<<t[i].stmin<<":";
			if(t[i].stsec<=9) cout<<"0";
			cout<<t[i].stsec<<"\n";
		} 
	}
	return 0;
} 
