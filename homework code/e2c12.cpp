#include<bits/stdc++.h>
using namespace std;
class String{
        public:
               String(const char *s);
               String();
               String(const String &s);
               ~String();
               int length() const;
               void stringlow();
               void stringup();
               int has(char x);
               String operator=(const String &s);
               String operator=(const char *s);
               char operator[](int i);
	       const char operator[](int i) const;
	       String operator+(const String &s) const;
	       String operator+(const char *s) const;
	       friend bool operator<(const String &s1,const String &s2);
	       friend bool operator>(const String &s1,const String &s2);
	       friend bool operator==(const String &s1,const String &s2);
	       friend ostream& operator<<(ostream &os, const String &st);
	       friend istream& operator>>(istream &is, String &st);
	       friend String operator+(const char*,const String &);
	       static int HowMany();
       private:
	       char *str;
	       int len;
	       static int num_strings;
	       static const int CINLIM=80;
};
int String::length() const
{
	return len;
}
int  String::num_strings=0;
int  String::HowMany()
{
	return num_strings;
}
String::String(const char*s)
{
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	num_strings++;
}
String::String()
{
	len=1;
	str=new char[1];
	str[0]='\0';
	num_strings++;
}
String::String(const String &s) 
{
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str, s.str);
	num_strings++;
}
String::~String()
{
	num_strings--;
	delete []str;
}
void String::stringup()
{
	for(int i=0;i<=len-1;i++)
	{
		if(islower(str[i])) str[i]=toupper(str[i]);
	}
}
void String::stringlow()
{
        for(int i=0;i<=len-1;i++)
	{
	        if(isupper(str[i])) str[i]=tolower(str[i]);
	}
}
int String::has(char x)
{
         int count=0;
	 for(int i=0;i<=len-1;i++)
	 {
	        if(str[i]==x) count++;
	 }
	 return count;
}
String String::operator=(const String &s)
{
         if(this==&s) return *this;
	 delete []str;
	 len=s.len;
	 str=new char[len+1];
	 strcpy(str,s.str);
	 return *this;
}
String String::operator=(const char *s)
{
	delete []str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}
char String::operator[](int i) 
{
       	return str[i]; 
}
const char String::operator[](int i) const 
{
       	return str[i]; 
}
String String::operator+(const String &s) const
{
	int total_len=len+s.len;
	char *tmp=new char[total_len+1];
	strcpy(tmp,str);
	strcat(tmp,s.str);
	String str_new=tmp;
	delete []tmp;
	return str_new;
}
String String::operator+(const char *s) const
{
	String tmp=s;
        String sum=*this+tmp;
	return sum;
}
bool operator<(const String &s1, const String &s2) 
{
	return (strcmp(s1.str,s2.str)<0);
}
bool operator>(const String &s1, const String &s2) 
{
	return (strcmp(s1.str,s2.str)>0);
}
bool operator==(const String &s1, const String &s2) 
{
	return (strcasecmp(s1.str,s2.str)==0);
}
ostream& operator<<(ostream &os,const String &st)
{
	os<<st.str;
	return os;
}
istream& operator>>(istream &is,String &st)
{
	char tmp[String::CINLIM];
	is.get(tmp,String::CINLIM);
	if(is) st=tmp;
	while(is&&is.get()!='\n') continue;
	return is;
}
String operator+(const char *s1, const String &s2) 
{
       	return String(s1)+s2; 
}
int main() {
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name:\n";
	String s3;
	cout << s2; // overloaded << operator
	cin >> s3; // overloaded >> operator
	s2 = "My name is " + s3; // overloaded =, + operators
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup(); // converts string to uppercase
	cout << "The string " << s2 << "\ncontains " << s2.has('A')<< " 'A' characters in it.\n";
	s1 = "red"; // String(const char *),
// then String & operator=(const String&)
	String rgb[3] = { String(s1), String("green"), String("blue")};
	cout << "Enter the name of a primary color for mixing light:\n";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow(); // converts string to lowercase
		for (int i = 0; i < 3; i++) {
			if (ans == rgb[i]) { // overloaded == operator
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye\n";
	return 0;
}

