#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n,i,j;
   cin>>n;
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n-i;j++)  cout<<".";
      for(j=1;j<=i;j++)  cout<<"*";
      cout<<endl;
   }
}
