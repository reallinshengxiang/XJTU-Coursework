#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct point{
	ll x,y;
};
point p[5];
bool cmp(point pa,point pb)
{
	if(pa.x!=pb.x) return pa.x<pb.x;
	return pa.y<pb.y;
}
ll miny=1e9+1,maxy=-1e9-1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll i=1;i<=3;i++) 
	{
	    cin>>p[i].x>>p[i].y;
		miny=min(miny,p[i].y);
		maxy=max(maxy,p[i].y);
	}
	sort(p+1,p+4,cmp);
	if(miny==maxy) cout<<"2\n";
	else 
	{
		cout<<"3\n";
		cout<<p[2].x<<" "<<miny<<" "<<p[2].x<<" "<<maxy<<"\n";
	}
	cout<<p[1].x<<" "<<p[1].y<<" "<<p[2].x<<" "<<p[1].y<<"\n";
	cout<<p[3].x<<" "<<p[3].y<<" "<<p[2].x<<" "<<p[3].y<<"\n";
	return 0;
}