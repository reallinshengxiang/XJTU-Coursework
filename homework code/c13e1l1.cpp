#include<bits/stdc++.h>
using namespace std;
class Cd
{
	public:
		Cd();
		Cd(const char *s1,const char *s2,const int n1,const double n2);
		Cd(const Cd &d);
		virtual Cd & operator=(Cd const &d);
		virtual ~Cd(){}
		virtual void Report() const;
	protected:
		char performers[50];
	        char label[20];
	        int selections;
		double playtime;
};
class Classic:public Cd
{
	public:
		Classic();
		Classic(const char *s1,const char *s2,const char *s3,const int n1,const double n2);
		Classic(const Classic &c);
		virtual Classic & operator=(Classic const &c);
                virtual ~Classic();
		virtual void Report() const;
	private:
		char* primary_work;
};
Cd::Cd()
{
	performers[0]='\0';
	label[0]='\0';
	selections=playtime=0;
}
Cd::Cd(const char *s1,const char *s2,const int n1,const double n2)
{
	strncpy(performers,s1,50);
	strncpy(label,s2,20);
	selections=n1;
	playtime=n2;
}
Cd::Cd(const Cd &d)
{
	strncpy(performers,d.performers,50);
	strncpy(label,d.label,20);
	selections=d.selections;
	playtime=d.playtime;
}
Cd & Cd::operator=(Cd const &d)
{
	if(this==&d) return *this;
	strncpy(performers,d.performers,50);
        strncpy(label,d.label,20);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}
void Cd::Report() const
{
	cout<<"performer: "<<performers<<"\n"<<"label: "<<label<<"\n"<<"selection: "<<selections<<"\n"<<"playtime: "<<playtime<<"\n";
}
Classic::Classic():Cd()
{
	primary_work=nullptr;
}
Classic::Classic(const char *s1,const char *s2,const char *s3,const int n1,const double n2):Cd(s1,s2,n1,n2)
{
	primary_work=new char[strlen(s3)+1];
	strcpy(primary_work,s3);
}
Classic::Classic(const Classic &c):Cd(c)
{
	primary_work=new char[strlen(c.primary_work)+1];
	strcpy(primary_work,c.primary_work);
}
Classic & Classic::operator=(Classic const &c)
{
	if(this==&c) return *this;
	delete []primary_work;
	Cd::operator=(c);
	primary_work=new char[strlen(c.primary_work)+1];
	strcpy(primary_work,c.primary_work);
	return *this;
}
Classic::~Classic()
{
	delete []primary_work;
}
void Classic::Report() const
{
	cout<<"performer: "<<performers<<"\n"<<"label: "<<label<<"\n"<<"primary work: "<<primary_work<<"\n"<<"selection: "<<selections<<"\n"<<"playtime: "<<playtime<<"\n";
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
