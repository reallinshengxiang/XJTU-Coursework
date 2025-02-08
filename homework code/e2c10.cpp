#include<bits/stdc++.h>
using namespace std;
class person{
	public:
		person(){lname="no lastname!";strcpy(fname,"no firstname!");}
		person(const string &ln,const char *fn="none");
		void show() const;
		void formalshow() const;
		friend istream& operator >>(istream& is,person & a);
		friend ostream& operator <<(ostream& os,const person & a);
	private:
		string lname;
		char fname[25];
};
person::person(const string &ln,const char *fn)
{
	lname=ln;
	strcpy(fname,fn);
}
void person::show() const
{
	cout<<fname<<" "<<lname<<"\n";
}
void person::formalshow() const
{
	cout<<"first name:"<<fname<<"\n"<<"last name:"<<lname<<"\n";
}
istream& operator >>(istream& is,person & a)
{
	cout<<"first name?\n";
	is>>a.fname;
	cout<<"last name?\n";
	is>>a.lname;
	return is;
}
ostream& operator <<(ostream& os,const person & a)
{
	os<<"first name:      "<<a.fname<<"\n"<<"last name:      "<<a.lname<<"\n";
	return os;
}
int main()
{
	person one;
        person two("Smythecraft");
        person three("Dimwiddy","Sam");
        cout<<"one:"<<"\n";
	one.show();
	one.formalshow();
	cout<<"\n";
	cin>>one;
	cout<<"one:"<<"\n";
	one.show();
	one.formalshow();
	cout<<"\n";
        cout<<"two:"<<"\n";
	two.show();
        two.formalshow();		
	cout<<"\n";
        cout<<"three:"<<"\n";				 		
	three.show();						
	three.formalshow();	
	cout<<"\n";
	return 0;
}

