#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	ll p,e,i,d,t,day,f1,f2,f3;
	t=0;
	while(1)
	{
		t++;
		cin>>p>>e>>i>>d;
		if(p==-1&&e==-1&&i==-1&&d==-1)  break;
		day=d+1;
		while((day-p)%23!=0&&day<21252) day++;
		while((day-e)%28!=0&&day<21252) day++;
		while((day-p)%33!=0&&day<21252) day=day+23*28;
		cout<<"Case "<<t<<": the next triple peak occurs in "<<day-d<<" days.\n";
	}
	return 0;
}
