#include<bits/stdc++.h>
using namespace std;
class juzhen{
    public:
	    juzhen(long long a,long long b,long long c,long long d):x(abs(a-c)),y(abs(b-d)) {}
	    long long zhouchang()
	    {
		  return 2*x+2*y;
	    }
	    long long mianji()
	    {
		  return x*y;
	    }
	    long long operator +(juzhen &b);
	    long long operator *(juzhen &b);
    private:
	    long long x,y;
};
long long juzhen::operator +(juzhen &b)
{
    return zhouchang()+b.zhouchang();
}
long long juzhen::operator *(juzhen &b)
{ 
     return mianji()+b.mianji();
}
int main()
{
    long long a[10],i;
    for(i=1;i<=8;i++) cin>>a[i];
    juzhen zj1(a[1],a[2],a[3],a[4]);
    juzhen zj2(a[5],a[6],a[7],a[8]);
    cout<<zj1+zj2<<" "<<zj1*zj2<<endl;
}
