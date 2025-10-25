#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,siz,ld,lr;
string ss,s;
char opt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>opt;
		if(opt=='C')
		{
			cin>>ss>>siz;
			s=ss+'/';
			cout<<s<<"\n";
		}
		else if(opt=='R')
		{
			cin>>ss;
			s=ss+'/';
			cout<<s<<"\n";
		}
		else if(opt=='Q')
		{
			cin>>ss>>ld>>lr;
			s=ss+'/';
			cout<<s<<"\n";
		}
	}
	return 0;
} 
