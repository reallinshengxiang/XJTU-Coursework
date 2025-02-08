#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,r,i,j,x;
    cin>>n>>r;
    for(i=1;i<=n;i++)
    {
       x=0;
       for(j=1;j<=r;j++)
       {
	   if(i%j==0) x++;
       }
       if(x%2==1) cout<<i<<" ";
    }
    cout<<endl;
}
