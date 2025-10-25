#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct island{
	double x,y;
};
island a[1010];
bool cmp(island xx,island yy)
{
	return xx.y<yy.y;
}
double d,xx,yy,last;
ll ans,n,flag;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>d)
	{
		if(n==0&&d==0) break;
		flag=1;
		for(ll i=1;i<=n;i++)
		{
			cin>>xx>>yy;
			if(abs(yy)>d) flag=0; 
			else
			{
				a[i].x=xx-sqrt(d*d-yy*yy);
				a[i].y=xx+sqrt(d*d-yy*yy);
			}
		}
		if(flag==0)
		{
			cout<<"-1\n";
			continue;
		}
		sort(a+1,a+n+1,cmp);
		last=a[1].y;
		ans=1;
		for(ll i=2;i<=n;i++)
		{
			if(a[i].x>last)
			{
				ans++;
				last=a[i].y;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
