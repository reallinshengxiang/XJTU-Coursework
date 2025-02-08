#include<bits/stdc++.h>
class StringBad
{
    public:
        StringBad(const char * s);
        StringBad();
        ~StringBad();
        friend std::ostream & operator<<(std::ostream & os,const StringBad & st);
    private:
        char * str;               
        int len;                  
        static int num_strings;    
};
using namespace std;
int StringBad::num_strings = 0;
StringBad::StringBad(const char * s)
{
    len =strlen(s);            
    str = new char[len + 1];        
    strcpy(str, s);         
    num_strings++;              
    cout << num_strings << ": \"" << str
         << "\" object created\n";
}

StringBad::StringBad()              
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");          // default string
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";  // FYI
}
StringBad::~StringBad()               // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";    // FYI
    --num_strings;                    // required
    cout << num_strings << " left\n"; // FYI
    delete [] str;                    // required
}
std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os; 
}
void callme1(StringBad &);
void callme2(StringBad);
int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lecttuce Prey");
        StringBad sports("Spinach Leaves Bow1 for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2:" << headline2 << endl;

        cout << "Initialize one object to another:\n\n";
        StringBad sailor = sports;//相当于运行了StringBad sailor = StringBad(sports);
        //在这里，编译器会自动调用复制构造函数StringBad(const StringBad &),从而使得
        //结果运行异常，结绝的方法是定义复制构造函数StringBad(const StringBad &)

        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "Exiting the block.\n\n";
        return 0;
    }

    cout << "End of main() \n\n";
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n\n";
    cout << "     \"" << rsb << "\"\n\n";
}

void callme2(StringBad sb)
{
    cout << "String passed by value: \n\n";
    cout << "      \"" << sb << "\"\n\n";
}
