#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll lim=3e7+5;
const ll maxn=7e7+5;
ll vis[maxn],prime[maxn],prime2[maxn],tot,top;
void find()
{
    vis[1]=1;
    for(ll i=2; i<lim; i++)
    {
        if (!vis[i]) prime[++tot]=i;
        for(ll j=1;j<=tot&&i*prime[j]<lim;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)   break;
        }
    }
    for (int i=1; i<=lim; i++)
    {
        if (!vis[2*i-1]) 
            prime2[++top]=i;
    }       
}
 
int main()
{   
    
    ios::sync_with_stdio(false);
	cin.tie(0);
    ll t,x;
	find();
    cin>>t;
    while (t--)
    {
        cin>>x;
        if(x==0) 
        { 
            cout<<"3\n";
            continue; 
        }
        if(x>0)
        {
            if(!vis[x]) 
            { 
                cout<<"1\n";
                continue; 
            }
            if (!vis[2*x+1]||!vis[x*2-1]) 
            { 
                cout<<"2\n"; 
                continue; 
            }
            ll ans=0x3f3f3f3f;
            ll pos=upper_bound(prime+1,prime+tot+1,x)-prime;
            ans=min(ans,prime[pos]*2);
            pos=upper_bound(prime2+1,prime2+lim+1,x)-prime2;
            ans=min(ans,2*prime2[pos]-1);
            cout<<ans<<"\n";
        }
        else if(x<0)
        {
            x=-x;
            ll ans=0x3f3f3f3f;
            ll pos=upper_bound(prime+1,prime+tot+1,x)-prime;
            ans=min(ans,prime[pos]*2);
            pos=upper_bound(prime2+1,prime2+top+1,x+1)-prime2;
            ans=min(ans,2*prime2[pos]-1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
