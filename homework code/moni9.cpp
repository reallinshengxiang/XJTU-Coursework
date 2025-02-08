#include <iostream>
 using namespace std;
 class complex //复数类
 {
 public:
 complex(double r=0.0,double i=0.0){real=r; imag=i;}//构造函数
 complex& operator ++(); //重载前置++
 void display()
 {
 cout<<real<<"+"<<imag<<"i"<<endl;
 }
 private:
 double real; //实部
 double imag; //虚部
};
complex& complex::operator ++()
{
	real=real+1;
	imag=imag+1;
	return *this;
}
int main()
 {
 complex c1(1,2),c2;
 c2=++c1;
 c1.display(); //输出2+3i
 c2.display(); //输出2+3i
 return 0;
 }
