#include<bits/stdc++.h>
using namespace std;
struct student
{
	long long x;
	double g;
	double w;
	double y;
	double z;
};
student a[5];
bool dy(student xx,student yy)
{
	if(xx.z<yy.z) return 1;
	else return 0;
}
int main()
{ 
   long long j=1,i;
    while(j<=4)
    {
    for(i=1;i<=30;i++) cout<<" ";
    if(j==1)  cout<<"1.Input"<<endl;
    else if(j==2) cout<<"2.Output"<<endl;
    else if(j==3) cout<<"3.Order"<<endl;
    else if(j==4) cout<<"4.Quit"<<endl;
    j++;
    }
    char c;
    cin>>c;
    if(c=='m') cout<<"You are trying to Make things ordered"<<endl;
    else if(c=='q') cout<<"You are about to Quit"<<endl;
    else if(c=='i')
	{
		  for(i=1;i<=3;i++)
          {
          scanf("%lld  %lf  %lf  %lf",&a[i].x,&a[i].g,&a[i].w,&a[i].y);
    	  a[i].z=a[i].g+a[i].w+a[i].y;
	     }
	     sort(a+1,a+4,dy);
	     for(i=1;i<=3;i++)
         {    
          printf("%lld  %.1lf  %.1lf\n",a[i].x,a[i].z,a[i].z/3);
	     }
	}
	else cout<<"Wrong input"<<endl;
}
