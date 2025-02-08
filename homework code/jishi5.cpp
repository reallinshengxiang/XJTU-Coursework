#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[101],i,j,s,n;
        cin>>n;;
	for(i=0;i<=n-1;i++)  cin>>a[i];
	cin>>s;
        for(i=0;i<=n-1;i++)
	{
           for(j=i+1;j<=n-1;j++)
	   {
		   if(a[i]+a[j]==s) 
		   {
			   cout<<"["<<i<<","<<j<<"]"<<endl;
			   return 0;
		   }
	   }
	}
}
