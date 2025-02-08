#include<bits/stdc++.h>
using namespace std;
static const double rad_to_deg=45/atan(1);
class Vector
{
	public:
		enum Mode {RECT, POL};
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
                void reset(double n1, double n2, Mode form = RECT);
		~Vector(){}
		double xval() const {return x;}
		double yval() const {return y;}
		double magval() const {return mag;}
		double angval() const {return ang;}
		void polar_mode() {mode=POL;}
		void rect_mode() {mode=RECT;}
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		friend Vector operator*(double n, const Vector & a);
		friend ostream & operator<<(std::ostream & os, const Vector & v);
	private:
		double x,y,mag,ang;
	        Mode mode;
		void set_mag();
	        void set_ang();
	        void set_x();
		void set_y();
};
Vector::Vector()
{
	x=y=mag=ang=0;
	mode=RECT;
}
void Vector::set_mag()
{
	mag=sqrt(x*x+y*y);
}
void Vector::set_ang()
{
	if(x==0&&y==0) ang=0;
	else ang=atan2(y,x);
}
void Vector::set_x()
{
	x=mag*cos(ang);
}
void Vector::set_y()
{
	y=mag*sin(ang);
}
Vector::Vector(double n1, double n2, Mode form)
{
	mode=form;
	if(mode==RECT)
	{
		x=n1;
		y=n2;
		set_mag();
		set_ang();
	}
	else if(mode==POL)
	{
		mag=n1;
		ang=n2/rad_to_deg;
		set_x();
		set_y();
	}
	else
	{
		cout<<"incorrect!\n";
		x=y=mag=ang=0;
		mode=RECT;
	}
}
void Vector::reset(double n1, double n2, Mode form)
{
        mode=form;
        if(mode==RECT)
        {
                x=n1;
                y=n2;
                set_mag();
                set_ang();
        }
        else if(mode==POL)
        {
                mag=n1;
                ang=n2/rad_to_deg;
                set_x();
                set_y();
        }
        else
        {
                cout<<"incorrect!"<<endl;
                x=y=mag=ang=0;
                mode=RECT;
        }
}
Vector Vector::operator+(const Vector & b) const
{
	return Vector(x+b.x,y+b.y);
}
Vector Vector::operator-(const Vector & b) const
{
	return Vector(x-b.x,y-b.y);
}
Vector Vector::operator-() const
{
	return Vector(-x,-y);
}
Vector Vector::operator*(double n) const
{
	return Vector(n*x,n*y);
}
Vector operator*(double n, const Vector & a)
{
	return a*n;
}
ostream & operator<<(std::ostream & os, const Vector & v)
{
	if(v.mode==Vector::RECT) os<<"(x,y)=("<<v.x<<","<<v.y<<")\n";
	else if(v.mode==Vector::POL) os<<"(m,a)=("<<v.mag<<","<<v.ang*rad_to_deg<<")\n";
	else cout<<"invaild\n";
	return os;
}
int main()
{
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        cout<<steps<<": "<<result;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction,Vector::POL);
            result = result + step;
            cout<<steps+1<<": "<<result;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}
