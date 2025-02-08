#include<bits/stdc++.h>
using namespace std;
class rectangle
{
   public:
	   rectangle(long long a,long long b,long long c,long long d):x(abs(c-a)),y(abs(d-b))
	   {
	   }
	   long long zhouchang()
	   {
	       return 2*x+2*y;
	   }
	   long long mianji()
	   {
		   return x*y;
	   }
	   long long x,y;
};
int main()
{
      long long a,b,c,d;
      cin>>a>>b>>c>>d;
      rectangle cfx(a,b,c,d);
      cout<<cfx.zhouchang()<<" "<<cfx.mianji()<<endl;
    
}
