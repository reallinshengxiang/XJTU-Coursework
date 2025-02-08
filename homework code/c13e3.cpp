#include<bits/stdc++.h>
using namespace std;
class ABC {
          private:
                 char* label;
                 int rating;
          public:
                 ABC(const char* l = "null", int r = 1);
                 ABC(const ABC& a);
                 virtual ~ABC() = 0;
                 virtual void View() const;
                 ABC& operator=(const ABC& a);
                 friend ostream& operator<<(ostream& os, const ABC& a);
};
class baseDMA : public ABC {
          public:
                 baseDMA(const char* l = "null", int r = 0);
                 friend ostream& operator<<(ostream& os, const baseDMA& rs);
};
class lacksDMA : public ABC {
          private:
                 enum { COL_LEN = 40 };
                 char color[COL_LEN];
          public:
                lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
                lacksDMA(const char* c, const ABC& a);
                virtual void View() const;
                friend ostream& operator<<(ostream& os, const lacksDMA& rs);
};
class hasDMA : public ABC {
          private:
                 char* style;
          public:
                 hasDMA(const char* s = "none", const char* l = "null", int r = 0);
                 hasDMA(const char* s, const ABC& c);
                 hasDMA(const hasDMA& hs);
                 ~hasDMA();
                 virtual void View() const;
                 hasDMA& operator=(const hasDMA& rs);
                 friend ostream& operator<<(ostream& os, const hasDMA& rs);
};
ABC::ABC(const char* l, int r)
{
	label=new char[strlen(l)+1];
	strcpy(label,l);
        rating=r;
}
ABC::ABC(const ABC& a)
{
	label=new char[strlen(a.label)+1];
	strcpy(label,a.label);
	rating=a.rating;
}
ABC::~ABC()
{
	delete []label;
}
void ABC::View() const
{
	cout<<*this;
}
ostream& operator<<(ostream& os, const ABC& a)
{
	os<<"label:"<<a.label<<endl<<"rating:"<<a.rating<<endl;
	return os;
}
ABC& ABC::operator=(const ABC& a)
{
	if(this==&a) return *this;
	delete []label;
	label=new char[strlen(a.label)+1];
	strcpy(label,a.label);
        rating=a.rating;
	return *this;
}
baseDMA::baseDMA(const char* l, int r):ABC(l, r) {}
ostream& operator<<(ostream& os, const baseDMA& rs) 
{
  os<<(const ABC&)rs;
  return os;
}
lacksDMA::lacksDMA(const char* c, const char* l, int r) : ABC(l, r) 
{
  strncpy(color, c, COL_LEN);
}
lacksDMA::lacksDMA(const char* c, const ABC& a) : ABC(a) {
  strncpy(color, c, COL_LEN);
}
void lacksDMA::View() const { cout<<*this; }
ostream& operator<<(ostream& os, const lacksDMA& rs) 
{
  os<<(const ABC&)rs<<"color:"<<rs.color;
  return os;
}
hasDMA::hasDMA(const char* s, const char* l, int r):ABC(l, r)
{
  style=new char[strlen(s)+1];
  strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const ABC& c):ABC(c)
{
  style=new char[strlen(s) + 1];
  strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs) : ABC(hs) 
{
  style = new char[strlen(hs.style)+1];
  strcpy(style, hs.style);
}
hasDMA::~hasDMA() { delete[] style; }
void hasDMA::View() const { cout<<*this; }
hasDMA& hasDMA::operator=(const hasDMA& hs) 
{
  if(this == &hs) return *this;
  ABC::operator=(hs);
  delete[] style;
  style=new char[strlen(hs.style)+1];
  strcpy(style, hs.style);
  return *this;
}
ostream& operator<<(std::ostream& os, const hasDMA& rs) 
{
  os<<(const ABC&)rs<<"style: "<<rs.style<<endl;
  return os;
}
int main()
{
  baseDMA shirt("Portrabelly", 8);
  lacksDMA balloon("red", "Blumpo", 4);
  hasDMA map("Mercator", "Buffalo Kyes", 5);
  cout << shirt << endl;
  cout << balloon << endl;
  cout << map << endl;
  lacksDMA balloon2(balloon);
  hasDMA map2;
  map2 = map;
  cout << balloon2 << endl;
  cout << map2 << endl;

  ABC* pts[3];
  pts[0] = &shirt;
  pts[1] = &balloon;
  pts[2] = &map;

  for (int i = 0; i < 3; ++i) cout << *pts[i] << endl;
  for (int i = 0; i < 3; ++i) pts[i]->View();

  return 0;
}
