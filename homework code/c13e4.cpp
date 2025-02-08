#include<bits/stdc++.h>
using namespace std;
class Port{
         private:
                char* brand;
                char style[20];
                int bottles;
         public:
                Port(const char* br = "none", const char* st = "none", int b = 0);
                Port(const Port& p);  // copy constructor
                virtual ~Port() { delete[] brand; }
                Port& operator=(const Port& p);
                Port& operator+=(int b); 
                Port& operator-=(int b);  // subtracts b from bottles, if available
                int BottleCount() const { return bottles; }
                virtual void Show() const;
                friend ostream& operator<<(ostream& os, const Port& p);
};
class VintagePort : public Port  // style necessarily = "vintage"
{
         private:
                char* nickname;  // i.e., "The Noble" or "Old Velvet", etc.
                int year;        // vintage year
         public:
                VintagePort();//派生类使用了动态内存分配，需要重新定义
                VintagePort(const char* br, int b, const char* nn, int y);//同上
                VintagePort(const VintagePort& vp);//同上
                ~VintagePort() { delete[] nickname; }
                VintagePort& operator=(const VintagePort& vp);
                void Show() const;
                friend ostream& operator<<(ostream& os, const VintagePort& vp);
};
Port::Port(const char* br, const char* st , int b)
{
	brand=new char[strlen(br)+1];
	strcpy(brand,br);
	strncpy(style,st,20);
	bottles=b;
}
Port::Port(const Port& p)
{
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
	strncpy(style,p.style,20);
	bottles=p.bottles;
}
Port& Port::operator=(const Port& p)
{
	if(this==&p) return *this;
	delete [] brand;
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
        strncpy(style,p.style,20);
        bottles=p.bottles;
	return *this;
}
Port& Port::operator+=(int b) 
{
        bottles=bottles+b;
        return *this;
}
Port& Port::operator-=(int b) 
{
        bottles=bottles-b;
        return *this;
}
void Port::Show() const 
{
        cout<<"Brand: "<<brand<<endl;
        cout<<"Style: "<<style<<endl;
        cout<<"Bottles: "<<bottles<<endl;
}
ostream& operator<<(ostream& os, const Port& p) 
{
        os<<p.brand<<", "<<p.style<<", "<<p.bottles;
        return os;
}
VintagePort::VintagePort():Port()
{
        nickname=new char[strlen("no name!")+1];
	strcpy(nickname,"no name!");
	year=0;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y):Port(br, "Vintage", b)
{
	nickname=new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year=y;
}
VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{
	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}
VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if(this==&vp) return *this;
	Port::operator=(vp);
	delete []nickname;
	nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
	year=vp.year;
	return *this;
}
void VintagePort::Show() const
{
	Port::Show();
	cout<<"nickname: "<<nickname<<endl;
	cout<<"year: "<<year<<endl;
}
ostream& operator<<(ostream& os, const VintagePort& vp)
{
	//os<<(const Port&)vp;
	os<<(const Port &) vp;
	os<<", "<<vp.nickname<<", "<<vp.year;
	return os;
}
int main() {
  Port p1;
  Port p2("Abc", "Bcc", 30);
  std::cout << p1 << std::endl;
  std::cout << p2 << std::endl;
  Port p3 = p2;
  p3.Show();
  p3 += 3;
  p3.Show();
  Port p4 = p2;
  p3 -= 2;
  p3.Show();

  VintagePort vp1("Vabc", 50, "hn", 1983);
  vp1.Show();
  VintagePort vp2;
  vp2.Show();
  vp1 -= 3;
  vp2 = vp1;
  std::cout << vp2 << std::endl;
  return 0;
}
