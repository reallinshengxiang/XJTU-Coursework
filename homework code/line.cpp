#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long t,i,j,ans,s,b[200020],n,q,c[20020];
   scanf("%lld",&t);
   for(i=1;i<=t;i++)
   {
       memset(b,0,sizeof(b);
       memset(c,0,sizeof(c));
      scanf("%lld",&n);
      char a[200002];
      s=0;
      for(j=1;j<=n;j++)
      {
         cin>>a[j];
        if(a[j]=='L') b[j]=j-1;
        else b[j]=n-j;
        s=s+b[j];
      }
      for(j=1;j<=n;j++)
      {
         if(a[j]=='L') c[j]=max(0,n-j-b[j]);
         else c[j]=max(0,j-1-b[j]);
      }
      sort(c+1,c+n+1);
      for(j=1;j<=n;j++)
      {
         ans=s;
         for(q=0;q<=j-1;q++)
         {
             ans=ans+c[n-q];
         }
         if(j!=n) printf("%lld ",ans);
         else printf("%lld\n",ans);
      }
   }
}
