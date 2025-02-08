#include<bits/stdc++.h>
using namespace std;
class person{
	public:
		person(){lname="";fname[0]='\0';}
		person(const string &ln,const char *fn="Heyyou");
		void show() const;
		void formalshow() const;
	private:
		static const int  LIMIT=25;
		string lname;
		char fname[LIMIT];
};
person::person(const string &ln,const char *fn)
{
	lname=ln;
	strcpy(fname,fn);
}
void person::show() const
{
	cout<<fname<<" "<<lname<<endl;
}
void person::formalshow() const
{
	cout<<"first name:"<<fname<<endl<<"last name:"<<lname<<endl;
}
int main()
{
	person one;
	person two("Smythecraft");
	person three("Dimwiddy","Sam");
	cout<<"one:"<<endl;
	one.show();
	one.formalshow();
	cout<<endl;
        cout<<"two:"<<endl;
	two.show();
	two.formalshow();
	cout<<endl;
	cout<<"three:"<<endl;
	three.show();
	three.formalshow();
        cout<<endl;
}
