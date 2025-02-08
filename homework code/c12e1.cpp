#include<bits/stdc++.h>
using namespace std;
class Cow{
	private:
               char name[20];
               char * hobby;
               double weight;
        public:
               Cow();
               Cow(const char * nm, const char * ho, double wt);
               Cow(const Cow &c);
               ~Cow();
               Cow & operator=(const Cow & c);
               void ShowCow() const; // display all cow data
};
Cow::Cow()
{
	name[0]='\0';
	hobby=NULL;
	weight=0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name,nm,20);
	hobby=new char[strlen(ho)+1];
	strcpy(hobby,ho);
    weight=wt;
}
Cow::Cow(const Cow &c)
{
	strncpy(name,c.name,20);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
}
Cow::~Cow()
{
	delete []hobby;
}
Cow & Cow::operator=(const Cow & c)
{
	if(this==&c) return *this;
	delete []hobby;
	strncpy(name,c.name,20);
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	weight=c.weight;
        return *this;
}
void Cow::ShowCow() const
{
	cout<<"name:"<<name<<endl<<"hobby:"<<hobby<<endl<<"weight:"<<weight<<endl;
}
int main()
{
	Cow a("old cow","sleep",100),b=a,c;
	a.ShowCow();
	b.ShowCow();
	c=a;
	c.ShowCow();
}
