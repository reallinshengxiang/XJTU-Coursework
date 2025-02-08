#include<bits/stdc++.h>
using namespace std;
long long s,d,h,m,ss;
int main()
{
     cin>>s;
     ss=s;
     if(s>=86400)
     {
	 d=s/86400;
	 s=s-d*86400;
     }
     if(s>=3600)
     {
	 h=s/3600;
	 s=s-h*3600;
     }
     if(s>=60)
     {
	 m=s/60;
	 s=s-60;
     }
     cout<<ss<<" seconds = "<<endl;
      
}
