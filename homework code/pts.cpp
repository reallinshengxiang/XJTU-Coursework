#include<bits/stdc++.h>
using namespace std;
class point
{
	public:
		point(const double &xx=0,const double &yy=0):x(xx),y(yy){}
		friend ostream & operator <<(ostream &os,const point &po);
		friend istream & operator >>(istream &is,point &po);
		virtual void display() const;
	protected:
		double x,y;
};
class sibianxing: public point
{
	public:
		sibianxing(const double &xx=0,const double &yy=0,const double &aa=0,const double &bb=0):point(xx,yy),c(aa),d(bb){}
		friend ostream & operator <<(ostream &os,const sibianxing &po);
		friend istream & operator >>(istream &is,sibianxing &po);
		virtual void display() const;
	private:
		double c,d;
};
ostream & operator <<(ostream &os,const sibianxing &po)
{
	os<<"("<<po.x<<","<<po.y<<","<<po.c<<","<<po.d<<")\n";
	return os;
}
istream & operator >>(istream &is,sibianxing &po)
{
	is>>po.x>>po.y>>po.c>>po.d;
	return is;
}
void sibianxing::display() const
{
	cout<<"display  "<<"("<<x<<","<<y<<","<<c<<","<<d<<")\n";
}
ostream & operator <<(ostream &os,const point &po)
{
	os<<"x: "<<po.x<<"    "<<"y: "<<po.y<<"\n";
	return os;
}
istream & operator >>(istream &is,point &po)
{
	cout<<"x:";
	is>>po.x;
	cout<<"y:";
	is>>po.y;
	return is;
}
void point::display() const
{
	cout<<"display       "<<"x: "<<x<<"    "<<"y: "<<y<<"\n";
}

int main()
{
	point a(1,1),b,*pc;
	a.display();
	sibianxing c(1,1,1),d,*pb=&c;
	cin>>b;
	cout<<b;
	pb->display();
	cout<<c;
	cin>>d;
	cout<<d;
	pb=&d;
	//pc=&c;
	pb->display();
}
