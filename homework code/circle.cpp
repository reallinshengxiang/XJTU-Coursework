#include<bits/stdc++.h>
using namespace std;
class circle{
	public:
		circle(double x=0):r(x),s(3.14*r*r),c(6.28*r){}
		circle(const circle &a);
		void show();
	private:
		double r,c,s;
};
circle::circle(const circle &a)
{
	r=a.r;
	c=a.c;
	s=a.s;
}
void circle::show()
{
	cout<<r<<" "<<c<<" "<<s<<endl;
}
int main()
{
	double x;
	cin>>x;
	circle c1(x),c2;
	c2=c1;
	c2.show();
}
