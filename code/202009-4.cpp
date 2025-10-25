#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#define ll int
#define ld double
const ll N=2e3+10;
struct point{
	ld x[110],dis;
};
point p[N];
ld ans,dis[N][N],theta,r;
ll n,m;
ld hailun(ld a,ld b,ld c)
{
	ld p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
ll dunjiao(ld a,ld b,ld c)
{
	if(b*b+c*c-a*a<0) return 1;
	if(a*a+c*c-b*b<0) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>r;
	for(ll i=1;i<=n;i++) cin>>p[0].x[i];
	for(ll i=1;i<=m;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cin>>p[i].x[j];
		    p[i].x[j]=p[i].x[j]-p[0].x[j];
		    p[i].dis=p[i].dis+p[i].x[j]*p[i].x[j];
		}
		p[i].dis=sqrt(p[i].dis);
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=i+1;j<=m;j++)
		{
			for(ll k=1;k<=n;k++) dis[i][j]=dis[i][j]+(p[i].x[k]-p[j].x[k])*(p[i].x[k]-p[j].x[k]);
			dis[i][j]=sqrt(dis[i][j]);
			dis[j][i]=dis[i][j];
		}
	}
	for(ll i=1;i<=m;i++)
	{
		ans=0;
		for(ll j=1;j<=m;j++)
		{
			if(i==j) continue;
			ld disij=dis[i][j];
			ld s=hailun(p[i].dis,p[j].dis,disij);
			ld h=2.0*s/disij;
			ll flag=dunjiao(p[i].dis,p[j].dis,disij);
			if((h>=r)||(h<=r&&flag)) 	ans=ans+disij;//cout<<i<<"  "<<j<<"    "<<1<<"       "<<fixed<<setprecision(14)<<ans<<"\n";
			else
			{
				theta=acos((p[i].dis*p[i].dis+p[j].dis*p[j].dis-disij*disij)/(2*p[i].dis*p[j].dis));
				ld theta1=acos(r/p[i].dis);
				ld theta2=acos(r/p[j].dis);
				theta=theta-theta1-theta2;
				//cout<<theta<<"     "<<(p[i].dis*p[i].dis+p[j].dis*p[j].dis-disij*disij)/(2*p[i].dis*p[j].dis)<<"         "<<p[i].dis<<"  "<<p[j].dis<<"  "<<disij<<"\n";
			    //cout<<sqrt(p[i].dis*p[i].dis-r*r)<<"    "<<sqrt(p[j].dis*p[j].dis-r*r)<<"        "<<r*theta<<"   "<<"r="<<r<<"    "<<"theta="<<theta<<"\n";
				ans=ans+sqrt(p[i].dis*p[i].dis-r*r)+sqrt(p[j].dis*p[j].dis-r*r)+r*theta;
			   // cout<<i<<"  "<<j<<"    "<<2<<"       "<<fixed<<setprecision(14)<<ans<<"\n";
			}			
		}
		cout<<fixed<<setprecision(14)<<ans<<"\n";
	}
	return 0;
} 
