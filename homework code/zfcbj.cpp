#include<bits/stdc++.h>
using namespace std;
int main()
{
    string *p1,*p2,*p3,s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s3);
    p1=&s1;
    p2=&s2;
    p3=&s3;
    if(*p1<*p2) p1=p2;
    if(*p1<*p3) p1=p3;
    cout<<*p1<<endl;
}
