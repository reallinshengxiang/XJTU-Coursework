#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
ll s[N],ss[N],b[N],d,n,num,cnt,nn;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>d>>n;
	cnt=nn=1;
	s[1]=d;
	ll pos=d;
	for(ll ii=1;ii<=n-1;ii++)
	{
		ll cnt=0;
		for(ll i=1;i<=nn;i++) b[i]=s[i];//cout<<s[i];
		//cout<<"\n";
		pos=b[1];
		for(ll i=1;i<=nn;i++)
		{	
			if(b[i]==pos) num++;
			if(b[i]!=pos)
			{
				pos=b[i];
				cnt++;
				s[cnt]=b[i-1];
				ll tt=0;
				while(num)
				{
					tt++;
					ss[tt]=num%10;
					num=num/10;
				}
				for(ll k=tt;k>=1;k--)
				{
					cnt++;
					s[cnt]=ss[k];
				}
				num=1;
			}
			if(i==nn)
			{
				if(b[i]==pos)
				{
					cnt++;
					s[cnt]=b[i];
					ll tt=0;
					while(num)
					{
						tt++;
						ss[tt]=num%10;
						num=num/10;
					}
					for(ll k=tt;k>=1;k--)
					{
						cnt++;
						s[cnt]=ss[k];
					}
				}
				else
				{
					cnt++;
					s[cnt]=b[i];
					cnt++;
					s[cnt]=1;
				}
			}
		}
		nn=cnt;
	}
	for(ll i=1;i<=nn;i++) cout<<s[i];
	return 0; 
}
