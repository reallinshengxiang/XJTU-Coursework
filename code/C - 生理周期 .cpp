#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll p,e,i,d,t,day,f1,f2,f3;
	t=0;
	while(1)
	{
		t++;
		cin>>p>>e>>i>>d;
		if(p==-1&&e==-1&&i==-1&&d==-1)  break;
		day=d+1;
		f1=(day-p)%23;
		f2=day%28;
		f3=day%33;		
		while((!(f1==p&&f2==e&&f3==i))&&day<=21252)
		{   
			if(f1==p&&f2==e) day=day+644;
			else if(f2==e&&f3==i)  day=day+924;
			else if(f1==p&&f3==i)  day=day+759;
			else day=day+33;
		    f1=day%23;
		    f2=day%28;
		    f3=day%33;				
		}
		cout<<"Case "<<t<<": the next triple peak occurs in "<<day<<" days.\n";
	}
}
