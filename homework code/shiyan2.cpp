#include<bits/stdc++.h>
using namespace std;
class point{
	public:
		point(long long a,long long b):x(a),y(b){}
	       // friend point operator -(const point &xx,const point &yy);
            void shuchu()
		{
		     cout<<abs(x)<<" "<<abs(y)<<endl;
		}
        private:
		long long x,y;
};
//point operator -(const point &xx,const point &yy)
//{
//	point cc;
//	cc.x=xx.x-yy.x;
//	cc.y=xx.y-yy.y;
//	return cc;
//}
int main()
{
	long long a,b,c,d;
        cin>>a>>b>>c>>d;
	point p1(a,b),p2(c,d);
        p1.shuchu();
        p2.shuchu();
}
