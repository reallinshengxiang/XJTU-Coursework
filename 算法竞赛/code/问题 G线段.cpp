#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll a,b;
};
point p[1000010];
ll ans,n,last;
bool cmp(point aa,point bb)
{
    return aa.b<bb.b;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>p[i].a>>p[i].b;
    sort(p+1,p+n+1,cmp);
    last=-1;
    for(ll i=1;i<=n;i++)
    {
    	if(p[i].a>=last)
    	{
    		ans++;
    		last=p[i].b;
		}
	}
	cout<<ans;
    return 0;
}
