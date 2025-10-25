#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=110;
ll T,a[N],n;
int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>T;
    while(T--) 
	{
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i];
        cout<<T<<"\n";
        for(ll i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        ll majority=-1;
        if(a[0]==a[1]) majority=a[0];
		else
		{
            if(a[0]==a[2]) majority=a[0];
			else majority=a[1];
        }
        /*for(ll i=0;i<n;i++) 
		{
            if(a[i]!=majority)
			{
                cout<<i+1<<"\n";
                break;
            }
        }*/
    }
    return 0;
}
