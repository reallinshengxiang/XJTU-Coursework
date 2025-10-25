#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
ll n,m=N,num,flag,now,k,a[N],b[N];
char ch;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) 
	{
		cin>>ch;
		if(ch=='F') a[i]=1;
	}
	for(ll len=1;len<=n;len++)
	{
		memset(b,0,sizeof(b));
		flag=1;
		num=now=0;
		for(ll i=1;i<=n;i++)
		{
			now=now^b[i];
			if(a[i]^now==0)
			{
				if(i+len-1>n)
				{
					flag=0;
					break;
				}
				num++;
				now=now^1;
				b[i+len]=b[i+len]^1;				
			}
		}
		if(flag)
		{
			if(num<m)
			{
				m=num;
				k=len;
			}
		}
	}
	cout<<k<<" "<<m;
	return 0; 
}
