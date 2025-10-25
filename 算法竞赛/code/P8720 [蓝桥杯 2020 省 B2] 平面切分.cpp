#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1100;
struct line{
	double k,b;
	bool operator<(const line &x) const
	{
		if(k>x.k) return 1;
		if(k==x.k&&b>x.b) return 1;
		return 0;
	}
};
struct point{
	double x,y;
	bool operator<(const point &p) const
	{
		if(x>p.x) return 1;
		if(x==p.x&&y>p.y) return 1;
		return 0;
	}	
};
line a[N],x;
point p;
map<line,ll> mp;
ll n,num,ans,sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>x.k>>x.b;
		if(mp[x]) continue;
		mp[x]=1;
		num++;
		a[num]=x;
		sum=0;	
		map<point,ll> pp;
		for(ll j=1;j<=num-1;j++)
		{
			if(a[num].k!=a[j].k)
			{
				p.x=(a[j].b-a[num].b)*1.0/(a[num].k-a[j].k);
				p.y=a[num].k*(a[j].b-a[num].b)*1.0/(a[num].k-a[j].k)+a[num].b;			
		//		cout<<p.x<<" "<<p.y<<"\n";
				if(!pp[p])
				{
					pp[p]=1;
					sum++;
				}
			}
		}
		ans=ans+sum+1;
	//	cout<<ans<<"\n";
	}
	cout<<ans;
	return 0; 
}
