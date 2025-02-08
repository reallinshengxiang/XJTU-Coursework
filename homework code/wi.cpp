#include<bits/stdc++.h>
using namespace std;
class Cow {
	public:
		Cow();
		Cow(const char * nm, const char * ho, double wt);
		Cow(const Cow &c);
		~Cow();
		Cow & operator=(const Cow & c);
		void ShowCow() const; // display all cow data
	private:
	       	char name[20];
		char * hobby;
		double weight;
};
Cow::Cow()
{
	name[0]='\0';
	hobby=NULL;
	weight=0;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
	long long len;
	strncpy(name,nm,20);
	len=strlen(ho)+1;
	hobby=new char[len];
        strcpy(hobby,ho);
	weight=wt;
}
Cow::Cow(const Cow &c)
{
	long long len;
	strncpy(name,c.name,20);
        len=strlen(c.hobby)+1;
        hobby=new char[len];
        strcpy(hobby,c.hobby);
	weight=c.weight;
}
Cow &  Cow::operator=(const Cow & c)
{
	long long len;
	if(this==&c) return *this;
	strncpy(name,c.name,20);
	len=strlen(c.hobby)+1;
        hobby=new char[len];
       	strcpy(hobby,c.hobby);
        weight=c.weight;
	return *this;
}
Cow::~Cow()
{
	delete []hobby;
}
void Cow::ShowCow() const
{
	cout<<name<<" "<<hobby<<" "<<weight<<endl;
}
int main()
{
	char a[20],b[30];
	double x;
	cin>>a;
	cin.get();
	cin.getline(b,22);
	cin>>x;
        Cow c1(a,b,x);
	cin>>a;
	cin.get();
        cin.getline(b,22);
        cin>>x;
	Cow c2(a,b,x);
	Cow c3;
	c3=c1;
	c3.ShowCow();
	c3=c2;
	c3.ShowCow();
}
