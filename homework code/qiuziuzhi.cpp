#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long a[6],i;
   for(i=0;i<=4;i++) cin>>a[i];
   sort(a,a+5);
   cout<<a[0]<<" "<<a[4]<<endl;
}
