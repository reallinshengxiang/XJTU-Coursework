#include<bits/stdc++.h>
using namespace std;
class Cd{
protected:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(const char* s1,const char* s2, int n, double x);
	Cd();
	virtual void Report() const;
	virtual Cd& operator=(const Cd& d);
};
Cd::Cd(const char *s1,const char *s2,int n,double x): selections(n), playtime(x)
{
	strcpy(performers,s1);
	strcpy(label,s2);
}
Cd::Cd(){}
void Cd::Report() const 
{
    cout<<performers<<","<<label<<","<<selections<<","<<playtime<<endl;
}
Cd & Cd::operator=(const Cd& d)
{
	if(this==&d) return *this;
	strcpy(performers,d.performers);
	strcpy(label,d.label);
	selections=d.selections;
	playtime=d.playtime;
	return *this;
}
class Classic : public Cd
{
 protected:
	char majorworkers[100];
 public:
	Classic(const char* s1,const char* s2,const char* s3,int n,double x);
	Classic();
	void Report() const;
	Classic& operator=(Classic& c);
};
Classic::Classic(const char* s1,const char* s2,const char* s3, int n, double x): Cd(s2,s3,n,x)
{
	strcpy(majorworkers, s1);
}
Classic::Classic() {} 
void Classic::Report()const
{
	cout<<majorworkers<<","<<performers<<","<<label<<","<<selections<<","<<playtime<<endl;
}
Classic& Classic::operator=(Classic& c)
{
	if(this==&c) return *this;
	strcpy(majorworkers, c.majorworkers);
	strcpy(performers,c.performers);
	strcpy(label,c.label);
	selections=c.selections;
	playtime=c.playtime;
	return *this;
}
void Bravo(const Cd & disk)
{
	disk.Report();
}
int main() 
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();
    cout<<"Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: "; //注意此处冒号后有一个空格
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}
