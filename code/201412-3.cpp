#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
const double eps=0.0001;
struct gupiao{
	ll buyorsell,s,flag;
	double p;
};
gupiao a[N],b[N],c[N],d[N];
ll num1,num2,cnt,x,sum1[N],sum2[N],maxans,tt;
double ans;
string s;
bool cmp(gupiao x,gupiao y)
{
	return x.p<y.p;
}
ll check(double x)
{
	ll pos1=num1+1,pos2=0,sum;
	for(ll i=1;i<=num1;i++)
	{
		if(b[i].p>=x)
		{
			pos1=i;
			break;
		}
	}
	for(ll i=1;i<=num2;i++)
	{
		if(c[i].p>x) break;
		else pos2=i;
		
	}
	sum=min(sum1[num1]-sum1[pos1-1],sum2[pos2]);
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>s)
	{
		if(s[0]=='b')
		{
			cnt++;
			a[cnt].buyorsell=0;
			cin>>a[cnt].p>>a[cnt].s;
		}
		else if(s[0]=='s')
		{
			cnt++;
			a[cnt].buyorsell=1;
			cin>>a[cnt].p>>a[cnt].s;
		}
		else
		{
			cin>>x;
			cnt++;
			a[cnt].flag=1;
			a[x].flag=1;
		}
	}
	for(ll i=1;i<=cnt;i++)
	{
		if(a[i].buyorsell==0&&!a[i].flag) 
		{
			num1++;
			b[num1]=a[i]; 
			tt++;
			d[tt]=a[i];
		}
		else if(a[i].buyorsell==1&&!a[i].flag)
		{
			num2++;
			c[num2]=a[i];
			tt++;
			d[tt]=a[i];
		}		
	}
	sort(b+1,b+num1+1,cmp);
	sort(c+1,c+num2+1,cmp);
	sort(d+1,d+tt+1,cmp);
	for(ll i=1;i<=num1;i++) sum1[i]=sum1[i-1]+b[i].s;
	for(ll i=1;i<=num2;i++) sum2[i]=sum2[i-1]+c[i].s;
	for(ll i=1;i<=tt;i++)
	{
		if(maxans<=check(d[i].p))
		{
			maxans=check(d[i].p);
			ans=d[i].p;
		}
	}
	cout<<fixed<<setprecision(2)<<ans<<" "<<maxans;
	return 0;
}
