#include<bits/stdc++.h>
using namespace std;
class Complex{
	public:
		Complex() {x=y=0;}
		Complex(double aa,double bb):x(aa),y(bb){}
		friend istream & operator>>(istream &is,Complex &n);
		friend ostream & operator<<(ostream &os,const Complex &n);
		Complex operator +(const Complex &n);
		Complex operator -(const Complex &n);
		Complex operator *(const double &n);
	        friend Complex operator *(double n,const Complex &a);
		Complex operator *(const Complex &n);
		Complex operator ~();
        private:
		double x;
		double y;
};
Complex operator *(double n,const Complex &a)
{
	Complex c;
	c.x=n*a.x;
	c.y=n*a.y;
	return c;
}
istream & operator>>(istream &is,Complex &n)
{
	cout<<"real:";
	is>>n.x;
	cout<<"imaginary:";
	is>>n.y;
	return is;
}
ostream & operator<<(ostream &os,const Complex &n)
{
	if(n.y==0) os<<n.x<<endl;
	else if(n.y>0)
	{
		os<<n.x<<"+"<<n.y<<"i"<<endl;
	}
	else  os<<n.x<<n.y<<"i"<<endl;
	return os;
}
Complex Complex::operator +(const Complex &n)
{
	Complex a;
	a.x=x+n.x;
	a.y=y+n.y;
	return a;
}
Complex Complex::operator -(const Complex &n)
{
	Complex a;
	a.x=x-n.x;
	a.y=y-n.y;
	return a;
}
Complex Complex::operator *(const double &n)
{
	Complex a;
	a.x=x*n;
	a.y=y*n;
        return a;
}
Complex Complex::operator *(const Complex &n)
{
	Complex a;
	a.x=x*n.x-y*n.y;
	a.y=x*n.y+y*n.x;
	return a;
}
Complex Complex::operator ~()
{
	Complex a;
	a.x=x;
	a.y=-y;
	return a;
}
int main()
{
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while(cin >> c)
    {
        cout << "c is " << c <<'\n';
        cout << "complex conjugate is " << ~c <<'\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n"; 
    }
    cout << "Done! \n";
    return 0;
}

