#include<bits/stdc++.h>
using namespace std;
class Cd {  // represents a CD disk
         private:
                char performers[50];
                char label[20];
                int selections;   // number of selections
                double playtime;  // playing time in minutes
         public:
                Cd(const char* s1,const char* s2, int n, double x);
                Cd(const Cd& d);
                Cd();
                virtual ~Cd(){}
                virtual void Report() const;  // reports all CD data
                virtual Cd& operator=(const Cd& d);
};
class Classic : public Cd {
         private:
                char* primary_work;
         public:
                Classic(const char* sc,const char* s1,const char* s2, int n, double x);
                Classic(const Classic& c);
                Classic();
                virtual ~Classic();
                virtual void Report() const;
                virtual Classic& operator=(const Classic& c);
};
Cd::Cd(const char* s1,const char* s2, int n, double x)
{
	strncpy(performers,s1,50);
	strncpy(label,s2,20);
	selections=n;
	playtime=x;
}
Cd::Cd(const Cd& d)
{
	strcpy(performers,d.performers);
        strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
}
Cd::Cd()
{
	performers[0]='\0';
	label[0]='\0';
	selections=0;
	playtime=0;
}
void Cd::Report() const
{
	cout<<"performers:"<<performers<<endl;
	cout<<"label:"<<label<<endl;
	cout<<"selections:"<<selections<<endl;
	cout<<"playtime:"<<playtime<<endl;
}
Cd& Cd::operator=(const Cd& d)
{
	if(this==&d) return *this;
	strncpy(performers,d.performers,50);
	strncpy(label,d.label,20);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}
Classic::Classic(const char* sc,const char* s1,const char* s2, int n, double x):Cd(s1,s2,n,x)
{
	primary_work=new char[strlen(sc)+1];
	strcpy(primary_work,sc);
}
Classic::Classic(const Classic& c):Cd(c)
{
	primary_work=new char[strlen(c.primary_work)+1];
	strcpy(primary_work,c.primary_work);
}
Classic::Classic():Cd()
{
	primary_work=nullptr;
}
Classic::~Classic()
{
	delete []primary_work;
}
void Classic::Report() const
{
	Cd::Report();
	cout<<"primary_work:"<<primary_work<<endl;
}
Classic& Classic::operator=(const Classic& c)
{
	if(this==&c) return *this;
	delete []primary_work;
	Cd::operator=(c);
	primary_work=new char[strlen(c.primary_work)+1];
	strcpy(primary_work,c.primary_work);
	return *this;
}
void Bravo(const Cd &disk);
int main() {
  Cd c1("Beatles", "Capitol", 14, 35.5);
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1;
  cout << "Using object directly:\n";
  c1.Report();  // use Cd method
  c2.Report();  // use Classic method
  cout << "Using type cd * pointer to objects:\n";
  pcd->Report();  // use Cd method for cd object
  pcd = &c2;
  pcd->Report();  // use Classic method for classic object
  cout << "Calling a function with a Cd reference argument:\n";
  Bravo(c1);
  Bravo(c2);
  cout << "Testing assignment: ";
  Classic copy;
  copy = c2;
  copy.Report();
  return 0;
}
void Bravo(const Cd &disk) { disk.Report();}

