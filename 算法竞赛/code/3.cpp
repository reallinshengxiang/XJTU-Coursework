#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
ll ans,s,sum,ss;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum1,sum2;
	sum1=sum2=0;
	for(ll i=1;i<=12;i++) sum1=sum1+a[i];
	for(ll i=1;i<=12;i++) sum2=sum2+b[i];
	cout<<sum1<<" "<<sum2<<"\n";
	for(ll i=1900;i<=9999;i++)
	{
		sum=i%10+(i/10)%10+(i/100)%10+i/1000;
		for(ll j=1;j<=12;j++)
		{
			s=0;
			if(j>=10)	s=j/10+j%10;
			else s=j;
			ss=s;
			if((i%100==0&&i%400==0)||(i%100!=0&&i%4==0))
			{
				for(ll k=1;k<=b[j];k++)
				{
					s=ss;
					if(k>=10) s=s+k/10+k%10;
			        else s=s+k;
			        if(s==sum) ans++;
				} 			
			}
			else
			{
				for(ll k=1;k<=a[j];k++)
				{
					s=ss;
					if(k>=10) s=s+k/10+k%10;
			        else s=s+k;
			        if(s==sum) ans++;
				} 
			}		
			
		}
	}
	cout<<ans;
	return 0;
}
