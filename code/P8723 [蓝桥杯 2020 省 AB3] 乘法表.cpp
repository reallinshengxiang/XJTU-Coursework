#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ch[40],a[10],p;
void change(ll x)
{
	ll cnt=0;
	do{
		a[++cnt]=x%p;
		x=x/p;
	}while(x!=0);
	for(ll i=cnt;i>=1;i--) cout<<char(ch[a[i]]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=0;i<=9;i++) ch[i]=(ll)(i+'0');
	for(ll i=10;i<=35;i++) ch[i]=(ll)(i-10+'A');
	//for(ll i=0;i<=35;i++) cout<<char(ch[i])<<" ";
	cin>>p;
	for(ll i=1;i<=p-1;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			change(i);
			cout<<"*";
			change(j);
			cout<<"=";
			change(i*j);
			cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
