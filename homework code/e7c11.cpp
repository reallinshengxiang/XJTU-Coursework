#include<bits/stdc++.h>
using namespace std;
class Complex{
	public:
               Complex(const double &a=0,const double &b=0):x(a),y(b){}
	       friend ostream& operator <<(ostream &os,const Complex &c);
               friend istream& operator >>(istream &is,Complex &c);
	       Complex operator ~();
	       Complex operator +(const Complex &c);
	       Complex operator -(const Complex &c);
	       Complex operator *(const Complex &c);
	       Complex operator *(const double &n);
	       friend Complex operator *(const double &n,const Complex &c);
        private:
	       double x,y;
};
istream& operator >>(istream &is,Complex &c)
{
	cout<<"x?\n";
	is>>c.x;
	cout<<"y?\n";
	is>>c.y;
	return is;
}
ostream& operator <<(ostream &os,const Complex &c)
{
	os<<c.x;
	if(c.y>0) os<<"+"<<c.y<<"i\n";
	else if(c.y==0) cout<<"\n";
	else cout<<c.y<<"i\n";
	return os;
}
Complex Complex::operator ~()
{
	return Complex(x,-y);
}
Complex Complex::operator +(const Complex &c)
{
	return Complex(x+c.x,y+c.y);
}
Complex Complex::operator -(const Complex &c)
{
	return Complex(x-c.x,y-c.y);
}
Complex Complex::operator *(const Complex &c)
{
	return x*c.x-y*c.y;
}
Complex Complex::operator *(const double &n)
{
	return Complex(x*n,y*n);
}
Complex operator *(const double &n,const Complex &c)
{
	return Complex(c.x*n,c.y*n);
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

