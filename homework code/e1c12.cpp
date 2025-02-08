#include<bits/stdc++.h>
using namespace std;
class Cow
{
	public:
		Cow();
		Cow(const char *na,const char *ho,const double &we);
	        ~Cow();
		Cow(const Cow &c);
		Cow & operator=(const Cow &c);
		void ShowCow();
	private:
		char name[22];
		char *hobby;
		double weight;
};
Cow::Cow()
{
	name[0]='\0';
	hobby=nullptr;
	weight=0;
}
Cow::Cow(const char *na,const char *ho,const double &we)
{
	strncpy(name,na,22);
	hobby=new char[strlen(ho)+1];
	strcpy(hobby,ho);
	weight=we;
}
Cow::~Cow()
{
	delete []hobby;
}
Cow::Cow(const Cow &c)
{
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
        strncpy(name,c.name,22);
        weight=c.weight;
}
Cow & Cow::operator=(const Cow &c)
{
	if(this==&c) return *this;
	delete []hobby;
	hobby=new char[strlen(c.hobby)+1];
	strcpy(hobby,c.hobby);
	strncpy(name,c.name,22);
	weight=c.weight;
	return *this;
}
void Cow::ShowCow()
{
	cout<<"name:  "<<name<<"\nhobby: "<<hobby<<"\nweight: "<<weight<<"\n";
}
int main()
{
	Cow a("old cow","sleep",100),b=a,c;
	a.ShowCow();
	b.ShowCow();
	c=a;
	c.ShowCow();
        return 0;
}
