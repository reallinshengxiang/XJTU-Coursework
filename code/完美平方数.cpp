#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flag,x,t,ans,xx;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	while(ans<=2020)
	{
		x=t*t;
		flag=1;
		while(x!=0&&flag)
		{
			xx=x%10;
			if(xx!=0&&xx!=1&&xx!=4&&xx!=9)
			{
				flag=0;
				break;
			}
			x=x/10;
		}
		if(flag) 
		{
			ans++;
			cout<<ans<<"  "<<t<<"\n";
		}
		if(ans==2020) cout<<t*t<<"\n";
		t++;
	}
	return 0;
}
