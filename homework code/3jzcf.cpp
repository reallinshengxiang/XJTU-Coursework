#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,a[5][5],b[5][5],c[5][5];
    for(i=1;i<=3;i++)
    {
         for(j=1;j<=3;j++)
	 {
	    cin>>a[i][j];
         }
    }
    for(i=1;i<=3;i++)
    {
	  for(j=1;j<=3;j++)
       	{
           cin>>b[i][j];
        }
    }
    memset(c,0,sizeof(c));
    for(i=1;i<=3;i++)
    {
	 for(j=1;j<=3;j++)
         {
            for(k=1;k<=3;k++)
	    {
		 c[i][j]=c[i][j]+a[i][k]*b[k][j];
	    }
	 }
    }
    for(i=1;i<=3;i++)
    {
	 for(j=1;j<=3;j++)
	{
	   cout<<c[i][j]<<" "; 
	}
	 cout<<endl;
    }
}
