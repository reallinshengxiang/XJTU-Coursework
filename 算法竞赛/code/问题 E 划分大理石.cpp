#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum,tt,cnt,x,w[20020],f[20020];
int main()
{
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 while(1)
	 {
	 	sum=0;
	 	tt=0;
	 	cnt=0;
	 	for(ll i=1;i<=6;i++)
	 	{
	 		cin>>x;
	 		sum=sum+i*x;
	 		if(x==0) tt++;
	 		for(ll j=1;j<=x;j=j*2)
	 		{
	 			cnt++;
	 			w[cnt]=j*i;
	 			x=x-j;
			}
			if(x) 
			{
				cnt++;
				w[cnt]=x*i;
			}
		}
		if(tt==6) return 0;
		if(sum%2==1)
		{
			cout<<"Can't\n";
			continue;
		}
		memset(f,0,sizeof(f));
		f[0]=1;
		for(ll i=1;i<=cnt;i++)
		{
			for(ll j=sum/2;j>=w[i];j--) f[j]=max(f[j],f[j]+f[j-w[i]]);
		}
		if(f[sum/2]) cout<<"Can\n";
		else cout<<"Can't\n";
	 }
	 return 0; 
}
