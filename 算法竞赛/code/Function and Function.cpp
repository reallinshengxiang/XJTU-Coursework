#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[11]={1,0,0,0,1,0,1,0,2,1},T,x,k,xx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>T;
    while(T--)
    {
    	cin>>x>>k;
    	xx=0;
    	if(k==0)
    	{
    		cout<<x<<"\n";
    		continue;
		}
       	do{
    		xx=xx+f[x%10];
    		x=x/10;
		}while(x!=0);
		k--;
		if(k==0)
    	{
    		cout<<xx<<"\n";
    		continue;
		}
		while(k!=0&&xx!=0)
		{
			k--;
			x=xx;
			xx=0;
		    do{
			  xx=xx+f[x%10];
    		  x=x/10;
		    }while(x!=0);
		    if(xx==0) break;
		}
		if(k==0) cout<<xx<<"\n";
		else 
		{
			if(k%2) cout<<"1\n";
			else cout<<"0\n";
		}
	}
	return 0;
}