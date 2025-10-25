#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
int main()
{
     srand(time(0));
     int t=0;
     t=rand()%100;
     cout<<t<<"\n";
     while(t--)
     {
         int n=0;
         n=10000;
         cout<<n<<endl;
         for (int i=1;i<=n;i++)
         {
             int a=0,b=0;
             a=(rand()%10000000)<<8 | (rand()%10000000);
             b=(rand()%10000000)<<8 | (rand()%10000000);
             if (a>b)
             {
                 int temp=b;
                 b=a;
                 a=temp;
             }
             cout<<a<<" "<<b<<endl;
         }
 
     }
     return 0;
 }
