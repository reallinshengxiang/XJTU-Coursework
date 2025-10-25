#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=62510;
ll win[N],w,l,cnt;
char s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;cin>>s&&s!='E';i++)
	{
		if(s=='W')  win[i]=1; 
		else win[i]=2;
		cnt=i; 
	}
	cnt++;
	for(ll i=1;i<=cnt;i++)
	{
		if(win[i]==1) w++;
		else if(win[i]==2) l++;
		else if(win[i]==0)	cout<<w<<":"<<l<<"\n";
		if(abs(w-l)>=2)
		{
			if(max(l,w)>=11)
			{
				cout<<w<<":"<<l<<"\n";
				w=l=0;
			}
		}
	}
	cout<<"\n";
	w=l=0;
	for(ll i=1;i<=cnt;i++)
	{
		if(win[i]==1) w++;
		else if(win[i]==2) l++;
		else if(win[i]==0)	cout<<w<<":"<<l<<"\n";
		if(abs(w-l)>=2)
		{
			if(max(l,w)>=21)
			{
				cout<<w<<":"<<l<<"\n";
				w=l=0;
			}
		}
	}
	return 0;
}
