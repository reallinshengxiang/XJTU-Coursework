#include<bits/stdc++.h>
using namespace std;
struct student{
           long long xuehao;
           long long banji;
           string xingming;
           double chengji1;
           double chengji2;
           double chengji3;
           double zongfen;
};
student a[10];
bool dy(student x,student y)
{
        if(x.banji<y.banji) return 1;
        else if(x.banji==y.banji&&x.zongfen>y.zongfen) return 1;
        else return 0;
}
int main()
{
        long long i,t,flag,q,m=0,l;
        string ss;
        a[1]={10001,11,"Zhang",99.5,88.5,89.5};
        a[2]={10002,12,"Yang",77.9,56.5,87.5};
        a[3]={10003,11,"Liang",92.5,99.0,60.5};
        sort(a+1,a+4,dy);
        cin>>ss;
        l=ss.size(); 
        flag=0;
        q=0;
        if(ss[0]>='0'&&ss[0]<='9') flag=1;
        if(flag)
        {
           for(i=0;i<=l-1;i++) m=m*10+ss[i]-'0';
           for(i=1;i<=3;i++)
                      for(i=0;i<=l-1;i++) m=m*10+ss[i]-'0';
           for(i=1;i<=3;i++)
           {
              if(a[i].xuehao==m)
              {
                   q=i;
                   flag=1;
                   break;
              }
           }
        }
        else
        {
          for(i=1;i<=3;i++)
          {
              if(a[i].xingming==ss)
               {
                   q=i;
                   flag=1;
                   break;
               }
          }
        }
        if(q==0)
        {
               for(i=1;i<=3;i++) 
			   {
			        cout<<a[i].xuehao<<" "<<a[i].banji<<" "<<a[i].xingming;
					printf(" %.1lf %.1lf %.1lf\n",a[i].chengji1,a[i].chengji2,a[i].chengji3);  
			   }                   
        }
        else
        {
               for(i=1;i<=3;i++)
             {
                  if(i!=q)  
				  {
				  	cout<<a[i].xuehao<<" "<<a[i].banji<<" "<<a[i].xingming;
					printf(" %.1lf %.1lf %.1lf\n",a[i].chengji1,a[i].chengji2,a[i].chengji3);  
		     	 }   
             }
             cout<<"Are you sure(yes/no)?"<<endl;
            char cc;
           cin>>cc;
          if(cc=='n')
          {
           for(i=1;i<=3;i++) 
           {
           	  cout<<a[i].xuehao<<" "<<a[i].banji<<" "<<a[i].xingming;
					printf(" %.1lf %.1lf %.1lf\n",a[i].chengji1,a[i].chengji2,a[i].chengji3);  
		   }
          }
        }
}
