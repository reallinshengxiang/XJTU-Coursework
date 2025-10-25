#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n = 2020, ans = 0,t=0;
    while (ans<=2020)
    {
        int flag = 1;
        int x=t*t;
        while (x!=0)
        {
            int xx=x%10;
            if (xx!=0 && xx!=1 &&xx!=4 && xx!=9) 
			{
				flag=0; 
				break;
			}
            x/=10;
        }
        if (flag) ans++,cout<<ans<<" "<<t<<"\n";
        if(ans==2020) cout<<t*t<<"\n";
        t++;
    }
}

