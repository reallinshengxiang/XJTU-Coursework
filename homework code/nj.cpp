#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long n,i,a[100],b[100],s=0;
   cin>>n;
   for(i=1;i<=n;i++) cin>>a[i];
   for(i=1;i<=n;i++) cin>>b[i];
   for(i=1;i<=n;i++) s=s+a[i]*b[i];
   cout<<s<<endl;
}
