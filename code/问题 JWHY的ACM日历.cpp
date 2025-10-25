#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>d;
    cout<<"+---------------------+\n";
    for(ll i=1;i<=n;i++)
    {
    	if(t%7==0) cout<<"|";
    	if(i==1)
    	{
    		for(ll j=1;j<=d-1;j++) cout<<"...";
			t=d-1;	
		}		
		if(i>=1&&i<=9) cout<<".."<<i;
		else cout<<"."<<i;
		t++;
		if(t%7==0) cout<<"|\n";
	}
	if(t%7)
	{
		while(t%7)
		{
		  cout<<"...";
		  t++;
	    }
	 cout<<"|\n";   
	}	
    cout<<"+---------------------+\n";
	return 0;
}
