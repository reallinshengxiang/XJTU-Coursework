#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct rili{
	ll year,month,day;
};
rili r[5];
string s;
ll a[5],b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},cnt;
bool cmp(rili x,rili y)
{
	if(x.year<y.year) return 1;
	else if(x.year==y.year)
	{
		if(x.month<y.month) return 1;
		else if(x.month==y.month&&x.day<y.day) return 1;
        return 0;
	}
	return 0;
}
void check()
{
	if(a[2]!=2&&a[3]<=b[a[2]]&&a[2]<=12&&a[2]>=1&&a[3]>=1)
	{
		r[++cnt].year=2000+a[1];
		if(r[cnt].year>=2060) r[cnt].year=r[cnt].year-100;
		r[cnt].month=a[2];
		r[cnt].day=a[3];
	}
	if(a[2]==2)
	{
		if(((2000+a[1])%400==0)||((2000+a[1])%4==0&&(2000+a[1])%100!=0)&&a[1]<=59)
		{
			if(a[3]<=29&&a[3]>=1)
			{
				r[++cnt].year=2000+a[1];
		        r[cnt].month=a[2];
		        r[cnt].day=a[3];
			}
		}
		else if(((1900+a[1])%400==0)||((1900+a[1])%4==0&&(1900+a[1])%100!=0)&&a[1]>=60)
		{
			if(a[3]<=29&&a[3]>=1)
			{
				r[++cnt].year=1900+a[1];
		        r[cnt].month=a[2];
		        r[cnt].day=a[3];
			}
		}
		else 
		{
			if(a[3]<=b[2]&&a[3]>=1)
			{
				r[++cnt].year=2000+a[1];
				if(r[cnt].year>=2060) r[cnt].year=r[cnt].year-100;
		        r[cnt].month=a[2];
		        r[cnt].day=a[3];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	a[1]=(s[0]-'0')*10+(s[1]-'0');
	a[2]=(s[3]-'0')*10+(s[4]-'0');
	a[3]=(s[6]-'0')*10+(s[7]-'0');
	check();
	swap(a[1],a[3]);
	check();
	swap(a[2],a[3]);
	check();
	sort(r+1,r+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++) 
	{
		if(r[i].day==r[i-1].day&&r[i].year==r[i-1].year&&r[i].month==r[i-1].month) continue;
		cout<<r[i].year<<"-";
		if(r[i].month<=9) cout<<"0";
		cout<<r[i].month<<"-";
		if(r[i].day<=9) cout<<"0";
		cout<<r[i].day<<"\n";
	}
	return 0;
} 
