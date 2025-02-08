#include<bits/stdc++.h>
using namespace std;
int prime(long long h);
int main()
{
    long long i,m=0;
    for(i=1;i<=1000;i++)
    {
	if(prime(i))
	{
	     m++;
	     printf("%5lld",i);
	     if(m%5==0) cout<<endl;
	}
    }
}
int prime(long long h)
{
   long long i,flag=0;
   if(h==1) return 0;
   if(h==2) return 1;
   for(i=2;i<=sqrt(h);i++)
   {
	if(h%i==0)
	{
	 flag=1;
	 break;
	}
   }
   if(flag) return 0;
   else return 1;
 }
