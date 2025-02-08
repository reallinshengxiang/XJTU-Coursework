#include<bits/stdc++.h>
using namespace std;
long long fs(long long);
int main()
{
    long long n;
    cin>>n;
    n=fs(n);
    cout<<n<<endl;
}
long long fs(long long n)
{
   if(n==1||n==2) return 1;
   return fs(n-1)+fs(n-2);
}
