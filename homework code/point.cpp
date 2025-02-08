#include<bits/stdc++.h>
using namespace std;
class point{
	public:
		point(long long a=0,long long b=0):x(a),y(b){}
	        friend point operator -(const point &xx,const point &yy);
                void shuchu()
		{
		     cout<<abs(x)<<" "<<abs(y)<<endl;
		}
        private:
		long long x,y;
};
point operator -(const point &xx,const point &yy)
{
	point cc;
	cc.x=xx.x-yy.x;
	cc.y=xx.y-yy.y;
	return cc;
}
int main()
{
	long long a,b,c,d;
        cin>>a>>b>>c>>d;
	point p1(a,b),p2(c,d),p3;
        p3=p1-p2;
        p3.shuchu();	
}
