#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long j,t;
     cin>>t;
   for(j=1;j<=t;j++)
   {
     long long w=0,i,n;
     cin>>n;
     for(i=1;i<=n-3;i++)
     {
       cout<<i<<" ";
       w=w^i;
     }
     cout<<(1<<23)<<" "<<(1<<24)<<" "<<(w^(1<<23)^(1<<24))<<endl;
   }
}
