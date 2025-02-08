#include<bits/stdc++.h>
using namespace std;
class person{
        public:
                person();
                person(const char *pid,const char *pname,const char *psex,const char *pbirthday,const char*phome);
                person(const person &p);
                void show();
                ~person();
        private:
                char *id,*name,*sex,*birthday,*home;
};
person::person()
{
       id=NULL;
       name=NULL;
       sex=NULL;
       birthday=NULL;
       home=NULL;
}
person::person(const char *pid,const char *pname,const char *psex,const char *pbirthday,const char*phome)
{
        long long len;
        len=strlen(pid);
        id=new char[len];
        strcpy(id,pid);
        len=strlen(pname);
        name=new char[len];
        strcpy(name,pname);
        len=strlen(psex);
        sex=new char[len];
        strcpy(sex,psex);
        len=strlen(pbirthday);
        birthday=new char[len];
        strcpy(birthday,pbirthday);
        len=strlen(phome);
        home=new char[len];
        strcpy(home,phome);
}
person::person(const person &p)
{
        long long len;
        len=strlen(p.id);
        id=new char[len];
        strcpy(id,p.id);
        len=strlen(p.name);
        name=new char[len];
        strcpy(name,p.name);
        len=strlen(p.sex);
        sex=new char[len];
        strcpy(sex,p.sex);
        len=strlen(p.birthday);
        birthday=new char[len];
        strcpy(birthday,p.birthday);
        len=strlen(p.home);
        home=new char[len];
        strcpy(home,p.home);
}
void person::show()
{
        cout<<id<<" "<<name<<" "<<sex<<" "<<birthday<<" "<<home<<endl;
}
person::~person()
{
        delete []id;
		delete []name;
		delete []sex;
		delete []birthday;
		delete []home;
}
int main()
{
         char a[22],b[22],c[22],d[22],e[22];
         cin>>a>>b>>c>>d>>e;
         person p1(a,b,c,d,e),p2;
         p2=p1;
         p2.show();
}
