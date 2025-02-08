#include<bits/stdc++.h>
using namespace std;
class Plorg{
	public:
		Plorg();
		Plorg(const char *n,const int &ci);
		void setCI(const int &ci);
		void show();
	private:
		char name[20];
		int CI;
}; 
Plorg::Plorg()
{
	strcpy(name,"Plorga");
	CI=0;
}
Plorg::Plorg(const char *n,const int &ci)
{
	CI=ci;
	strcpy(name,n);
}
void Plorg::setCI(const int &ci)
{
	CI=ci;
}
void Plorg::show()
{
	cout<<"name:"<<name<<endl<<"CI:"<<CI<<endl;
}
int main()
{
    Plorg p1, p2("plorg2", 50);
    p1.show();
    p2.show();
    p1.setCI(30);
    p1.show();
}
