#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#pragma GCC optimize(2)
ll m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
ll bh[11]={13,1,2,3,5,4,4,2,2,2};
ll sum,lq,tt,qq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(ll year=2000;year<=2024;year++)
	{
		if(year%4==0&&year%100!=0) m[2]=29;
		else if(year%400==0) m[2]=29;
		else m[2]=28;
		tt=bh[year%10]+bh[year/1000]+bh[(year/10)%10]+bh[(year/100)%10];
		for(ll i=1;i<=12;i++)
	   {	   	    
		    if(i<=9) qq=tt+bh[0]+bh[i];
		    else qq=tt+bh[i%10]+bh[i/10];
		    for(ll j=1;j<=m[i];j++)
		    {
			    if(j<=9) sum=qq+bh[0]+bh[j];
			    else  sum=qq+bh[j%10]+bh[j/10];
			    if(sum>50) lq++;
			    cout<<year<<"  "<<i<<" "<<j<<"  "<<sum<<"\n";
			    if(year==2024&&i==4&&j==13) 
			    {
			    //	cout<<tt<<"  "<<qq<<"  "<<sum<<"\n";
			    	cout<<lq;
			    	return 0;
				}
		    }
		    
		    
	    }
	}
	return 0;
}
/*
3228
*/
