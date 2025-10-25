#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,x,y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>y;
    if(y>=0&&-x<=y&&y>=x) ans=4*y*y-2*y+(x+y);
    else if(x>=0&&y>=-x&&y<=x) ans=4*x*x+(x-y);
    else if(y<=0&&-x>=y&&y<=x) ans=4*y*y-2*y+(-y-x);
    else ans=4*x*x+2*x-(-x-y);
    cout<<ans;
	return 0;
}
