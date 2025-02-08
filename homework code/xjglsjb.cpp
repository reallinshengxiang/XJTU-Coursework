#include<bits/stdc++.h>
using namespace std;
struct student{
   long long id;
   long long banji;
   string name;
   double score1;
   double score2;
   double score3;
   double zongfen;
};
student a[10];
void print();
void input();
void del();
long long flag=1,sum;
int main()
{
   long long n;
    print();
    cin>>n;
    if(n==1) input();
    if(n==2) del();
}
void print()
{
   cout<<"1.input"<<endl<<"2.delete"<<endl<<"3.select"<<endl<<"4.order"<<endl<<"5.output"<<endl<<"6.quit"<<endl<<"please input your option"<<endl;
}
void input()
{
   string ss;
   long long i=0;
   while(flag)
   {
      i++;
      cin>>ss>>a[i].id>>ss>>a[i].banji>>ss>>a[i].name>>ss>>a[i].score1>>ss>>a[i].score2>>ss>>a[i].score3;
      a[i].zongfen=a[i].score1+a[i].score2+a[i].score3;
      cout<<"continue?"<<endl;
      string s;
      cin>>s;
      if(s=="yes") flag=1;
      else if(s=="no")
      {
	   flag=0;
	   print();
      }
      sum=i;
   }
   flag=1;
}
void del()
{
    long long i,num=0,l;
    string ss;
    while(flag)
   {
      cin>>ss;
      l=ss.size();
      long long f=0,k=0;
      if(ss[0]>='0'&&ss[0]<='9')
      {  
	   f=1;
          for(i=0;i<=l-1;i++)  num=mun*10+s[i]-'0';
      }

       for(i=1;i<=sum;i++)
      {
         if(a[i].id==num||a[i].name==ss)
	 {
	    k=i;
	    break;
	 }
      }
       if(k)
       {
	   for(i=k+1;i<=sum;i++) a[i-1]=a[i];
       }
       sum--;
       for(i=1;i<=sum;i++) cout<<fixed<<setprecision<<a[i].id<<","<<a[i].banji<<","<<a[i].name<<","<<a[i].score1<<","<<a[i].score2<<","<<a[i].score3<<","<<a[i].zongfen<<endl;
      cout<<"continue?"<<endl;
      string s;
      cin>>s;
      if(s=="yes") flag=1;
      else if(s=="no")
      {
        flag=0;
	print();
      }
   }
    flag=1;
}
