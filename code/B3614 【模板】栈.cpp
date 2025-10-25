#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll N=1e6+10;
ll st[N],T,n,x,cnt;
string s;
void push(ll x)
{
	cnt++;
	st[cnt]=x;
	return;
}
void pop()
{
	if(cnt>=1)	cnt--;
	else cout<<"Empty\n";
	return;
}
void query()
{
	if(cnt>=1) cout<<st[cnt]<<"\n";
	else cout<<"Anguei!\n";
	return;
}
void size()
{
	cout<<cnt<<"\n";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		memset(st,0,sizeof(st));
		cnt=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>s;
			if(s=="push") cin>>x,push(x);
			else if(s=="pop") pop();
			else if(s=="query") query();
			else if(s=="size") size();
		}
	}
	return 0;
}
